#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
long long solve(int a,int b,int c,int l) {
    long long res=0;
    FOR(i,a,a+l) {
        int tmp=min(l-(i-a),i-(b+c));
        if (tmp>=0) res+=1LL*(tmp+1)*(tmp+2)/2;
    }
    return (res);
}
int main(void) {
    int a,b,c,l;
    cin>>a>>b>>c>>l;
    long long res=0;
    FOR(i,0,l) res+=1LL*(i+1)*(i+2)/2;
    res-=solve(a,b,c,l);
    res-=solve(b,c,a,l);
    res-=solve(c,a,b,l);
    cout<<res<<endl;
    return 0;
}