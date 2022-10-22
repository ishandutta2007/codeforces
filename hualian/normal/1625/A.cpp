#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a[maxn],cnt[32],t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		int m,n;
		scanf("%d%d",&n,&m);
		rep(i,n)a[i]=read();
		ri ans=0;
		For(i,0,m-1){
			cnt[i]=0;
			rep(j,n)cnt[i]+=(a[j]>>i)%2;
			if(cnt[i]*2>n)ans|=(1<<i);
		}
		printf("%d\n",ans);
	}
}