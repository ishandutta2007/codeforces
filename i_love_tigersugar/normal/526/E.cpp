#include<bits/stdc++.h>
#define MAX   2000200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,q;
int a[MAX],range[MAX];
long long s[MAX];
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) a[n+i]=a[i];
    FOR(i,1,2*n) s[i]=s[i-1]+a[i];
}
int jump(int x) {
    int res=0;
    int cur=x;
    while (cur<x+n) {
        res++;
        cur=range[cur]+1;
    }
    return (res);
}
void answer(long long lim) {
    FOR(i,1,2*n) if (s[i]<=lim) range[1]=i;
    int j=range[1];
    FOR(i,2,2*n) {
        while (j<2*n && s[j+1]-s[i-1]<=lim) j++;
        range[i]=j;
    }
    //FOR(i,1,n) printf("%d ",range[i]); printf("\n");
    int idMin=1;
    int res=MAX;
    FOR(i,1,n) if (range[i]-i<range[idMin]-idMin) idMin=i;
    int L=idMin;
    int R=range[idMin];
    if (R<=n) {
        L+=n;R+=n;
    }
    FOR(i,L,R) res=min(res,jump(i>n?i-n:i));
    FOR(i,1,L) if (range[i]==R) {
        res=min(res,jump(i>n?i-n:i));
        break;
    }
    printf("%d\n",res);
}
void process(void) {
    REP(love,q) {
        long long x;
        cin>>x;
        answer(x);
    }
}
int main(void) {
    init();
    process();
    return 0;
}