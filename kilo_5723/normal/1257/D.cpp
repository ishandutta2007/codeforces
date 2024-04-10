#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2e5+5;
struct hero{ int p,s; };
inline bool operator < (const hero &a,const hero &b){
    return a.p<b.p;
}
int a[maxn];
hero b[maxn];
int c[maxn];
int n,m;
inline int get(int val){
    int pos=m;
    for (int i=1<<20;i;i>>=1) if (pos-i>=0&&b[pos-i].p>=val)
        pos-=i;
    return pos;
}
int main(){
    int tt;
    int i,p,q;
    int cnt,mxm;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        scanf("%d",&m);
        for (i=0;i<m;i++) scanf("%d%d",&b[i].p,&b[i].s);
        sort(b,b+m); c[m]=0;
        for (i=m-1;i>=0;i--) c[i]=max(c[i+1],b[i].s);
        p=0; cnt=0;
        while (p<n){
            q=p; mxm=0;
            while (p<n&&c[mxm=(max(mxm,get(a[p])))]>=p-q+1) p++;
            if (p==q){ cnt=-1; break; }
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}