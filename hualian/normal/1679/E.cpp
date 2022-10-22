#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int p=998244353;
const int N=1<<18;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
char s[N];
int A[N];
const int lim=1<<17;
void FWT_or(int *a){
	for(int len=2,k=1;len<=lim;len<<=1,k<<=1)
	for(int i=0;i<lim;i+=len)
	for(int j=0;j<k;j++)
	(a[i+j+k]+=a[i+j])%=p;
}
int ans[18][N];
int all;
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
void solve(int k){
	memset(A,0,sizeof A);
	rep(i,n){//i
		int S=0,cnt=1,now=all;
		if(s[i]=='?')(cnt*=k)%=p,now--;// 
		(A[0]+=cnt*inv(k,now))%=p;
		int j=1;
		while(i-j>=1&&i+j<=n){
			now-=(s[i-j]=='?');now-=(s[i+j]=='?');
			if(s[i-j]!='?'&&s[i+j]!='?'&&s[i-j]!=s[i+j])break;
			if(s[i-j]=='?'&&s[i+j]=='?')(cnt*=k)%=p;
			else if(s[i-j]!='?'&&s[i+j]!='?');
			else if(s[i-j]!='?')S|=(1<<(s[i-j]-'a'));
			else S|=(1<<(s[i+j]-'a'));
			(A[S]+=cnt*inv(k,now))%=p;
			j++;
		}
	}
//	if(k==1)cout<<A[0]<<" "<<A[1]<<endl;
	rep(i,n-1){//ii+1
		int S=0,cnt=1,now=all;
		int j=1;
		while(i-j+1>=1&&i+j<=n){
			now-=(s[i-j+1]=='?');now-=(s[i+j]=='?');
			if(s[i-j+1]!='?'&&s[i+j]!='?'&&s[i-j+1]!=s[i+j])break;
			if(s[i-j+1]=='?'&&s[i+j]=='?')(cnt*=k)%=p;
			else if(s[i-j+1]!='?'&&s[i+j]!='?');
			else if(s[i-j+1]!='?')S|=(1<<(s[i-j+1]-'a'));
			else S|=(1<<(s[i+j]-'a'));
			(A[S]+=cnt*inv(k,now))%=p;
			j++;
		}
	}
	FWT_or(A);
	For(i,0,(1<<17)-1)ans[k][i]=A[i]; 
}
char t[20];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();scanf("%s",s+1);
	rep(i,n)all+=s[i]=='?';
	rep(i,17)solve(i);
	int q=read();
	while(q--){
		scanf("%s",t+1);
		int S=0,m=strlen(t+1);
		rep(i,m)S|=(1<<(t[i]-'a'));
		cout<<ans[m][S]<<endl;
	}
	return 0;
}