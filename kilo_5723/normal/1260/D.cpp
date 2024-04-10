#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+5;
int n,m,k,t;
int a[maxn],l[maxn],r[maxn],d[maxn];
int cnt[maxn];
bool check(int val){
    int i,tot;
    memset(cnt,0,sizeof(cnt));
    for (i=0;i<k;i++) if (d[i]>val){
        cnt[l[i]]++; cnt[r[i]+1]--;
    }
    tot=0;
    for (i=1;i<=m+1;i++) cnt[i]+=cnt[i-1];
    for (i=0;i<=m+1;i++) tot+=(bool)cnt[i];
    return tot*2<=t-1-m;
}
int main(){
    int i,o,p,q;
    scanf("%d%d%d%d",&n,&m,&k,&t);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    for (i=0;i<k;i++) scanf("%d%d%d",&l[i],&r[i],&d[i]);
    sort(a,a+n); reverse(a,a+n);
    p=0; q=n+1;
    while (q-p>1){
        o=(p+q)/2;
        if (check(a[o-1])) p=o;
        else q=o;
    }
    printf("%d\n",p);
    return 0;
}