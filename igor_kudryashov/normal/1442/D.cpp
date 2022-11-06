#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){
   int s=0;
   char ch=getchar();
   while(ch<'0'||ch>'9') ch=getchar();
   while(ch>='0'&&ch<='9') s=s*10+(ch^48),ch=getchar();
   return s;
}
long long ans[3003],b[1000003];
using namespace std;
//inline int min(int &x,int &y) { return (x<y)?x:y; }
int main()
{
    int n=read(),k=read();
    for(;n--;) 
    {
        int m=read();
        for(int i=1; i<=m; ++i) b[i]=b[i-1]+read();
        m=min(m,k);
        for(int i=k; i>=1; --i) for(int j=1; j<=min(i,m); ++j) (ans[i]<ans[i-j]+b[j])&&(ans[i]=ans[i-j]+b[j]); 
    }
    printf("%lld\n",ans[k]);
	return 0;
}