#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const long long INF=(long long)1e15+7LL;
long long product(long long a,long long b) {
    if (a==0 || b==0) return (0);
    return (INF/a<=b?INF:a*b);
}
long long sum(long long l,long long r) {
    if ((l+r)%2==0) return (product((l+r)/2,r-l+1));
    else return (product(l+r,(r-l+1)/2));
}
int a,b,n;
long long sumCol(long long l,long long r) {
    long long A=product(r-l+1,a);
    long long B=product(sum(l-1,r-1),b);
    return (min(INF,A+B));
}
bool ok(long long l,long long r,long long t,long long m) {
    if (sumCol(l,r)>1LL*t*m) return (false);
    return (sumCol(r,r)<=t);
}
long long answer(long long l,long long t,long long m) {
    if (!ok(l,l,t,m)) return (-1);
    long long L=l;
    long long R=INF;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (ok(l,R,t,m)?R:L);
        long long M=(L+R)>>1;
        if (ok(l,M,t,m)) L=M; else R=M-1;
    }
}
void process(void) {
    cin>>a>>b>>n;
    REP(love,n) {
        int l,t,m;
        cin>>l>>t>>m;
        cout<<answer(l,t,m)<<"\n";
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    process();
    return 0;
}