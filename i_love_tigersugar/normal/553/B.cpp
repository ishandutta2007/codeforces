#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const long long INF=(long long)1e18+7LL;
long long frac[MAX],numPerm[MAX];
long long prod(long long a,long long b) {
    if (a==0 || b==0) return (0);
    return (INF/a<b?INF:a*b);
}
void precount(void) {
    frac[0]=1;
    FOR(i,1,MAX-1) frac[i]=prod(frac[i-1],i);
    numPerm[0]=1;
    numPerm[1]=1;
    FOR(i,2,MAX-1) numPerm[i]=min(INF,numPerm[i-1]+numPerm[i-2]);
}
int n,p[MAX];
long long pos;
void process(void) {
    cin>>n>>pos;
    pos--;
    int cnt=0;
    while (cnt<n) FOR(i,1,min(n-cnt,2)) {
        if (pos>=numPerm[n-cnt-i]) pos-=numPerm[n-cnt-i];
        else {
            if (i==1) p[cnt+1]=cnt+1;
            else {
                p[cnt+1]=cnt+2;
                p[cnt+2]=cnt+1;
            }
            cnt+=i;
            break;
        }
    }
    FOR(i,1,n) cout<<p[i]<<" ";
    cout<<endl;
}
int main(void) {
    precount();
    process();
    return 0;
}