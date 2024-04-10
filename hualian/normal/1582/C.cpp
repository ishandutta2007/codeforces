#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
char s[N],t[N];int cnt[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();while(T--)	{
		int n=read();scanf("%s",s+1);
		int ans=1e9;
		For(k,0,25){
			int len=0;
			For(i,0,n)cnt[i]=0;
			rep(i,n)
				if(s[i]==k+'a')cnt[len]++;
				else t[++len]=s[i];
			int f=1;
			rep(i,len/2)if(t[i]!=t[len-i+1]){f=0;break;}
			if(!f)continue;
			int res=0;
			For(i,0,len)
				res+=cnt[i]-min(cnt[i],cnt[len-i]);
				chmn(ans,res);
		}
		if(ans==1e9)puts("-1");
		else cout<<ans<<endl;
	}
	return 0;
}