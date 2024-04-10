#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=289;
namespace Reimu_Kawaii{
    char buf[1<<20],obuf[1<<20],*p1,*p2,*p3=obuf;
    #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
    #define putchar(x) (p3-obuf<1000000)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
    inline int read(){
        int x=0;char c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return x;
    }
    inline void write(int x){
        static char buf[15];
        static int len=-1;
        do buf[++len]=x%10+48,x/=10;while(x);
        while(len>=0)putchar(buf[len]),--len;
        putchar(' ');
    }
    inline void flush(){
        fwrite(obuf,p3-obuf,1,stdout),exit(0);
    }
    #undef getchar
    #undef putchar
}using namespace Reimu_Kawaii;
int n,d[N],p[N][N],C;
vector<int>a[N];
char s[N][N],q[N];
int l=1,r;
signed main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%s",s[i]+1);
		FOR(j,1,i-1)FOR(k,1,100)if(s[i][k]!=s[j][k]){
			if(!s[i][k]&&s[j][k])puts("Impossible"),exit(0);
			if(s[j][k])a[s[j][k]].pbk(s[i][k]),++d[s[i][k]],p[s[j][k]][s[i][k]]=1;
			break;
		}
	}
	FOR(i,'a','z')if(!d[i])q[++r]=i;
	while(l<=r){
		rgi x=q[l++];
		for(rgi to:a[x]){
			if(!--d[to])q[++r]=to;
		}
	}
	if(r!=26)puts("Impossible"),exit(0);
	FOR(i,1,26)FOR(j,0,i-1){
		if(p[q[i]][q[j]])puts("Impossible"),exit(0);
	}
	FOR(i,1,26)putchar(q[i]);
	flush();
}