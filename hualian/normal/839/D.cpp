#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1000010;
const int p=1e9+7; 
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
int sum[N],a[N],cnt[N];
int P[N],len,mu[N],vis[N];
int p2[N];
void init(int n=1000000){
	mu[1]=1;
	For(i,2,n){
		if(!vis[i])mu[i]=-1,P[++len]=i;
		for(int j=1;j<=len&&P[j]*i<=n;j++){
			vis[P[j]*i]=1;
			if(i%P[j]==0)break;
			mu[i*P[j]]=-mu[i];
		}
	}
	p2[0]=1;rep(i,n)p2[i]=(p2[i-1]<<1)%p;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();init();int ans=0;
	rep(i,n)sum[read()]++;
	rep(i,1000000)for(int j=i;j<=1000000;j+=i)
		(cnt[i]+=sum[j])%=p;
	rep(i,1000000)if(cnt[i])cnt[i]=p2[cnt[i]-1]*cnt[i]%p;
	rep(i,1000000)for(int j=i;j<=1000000;j+=i)
		(a[i]+=cnt[j]*mu[j/i])%=p;
	For(i,2,1000000)(ans+=a[i]*i)%=p;
	cout<<ans<<endl;
	return 0;
}
///////////////