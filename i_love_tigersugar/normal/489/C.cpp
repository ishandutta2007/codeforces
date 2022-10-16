#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int main(void) {
    int m,s;
    cin>>m>>s;
    if (m==1) {
        if (s>9) cout<<"-1 -1";
        else cout<<s<<" "<<s;
        return 0;
    }
    if (s<1 || s>9*m) {
        cout<<"-1 -1";
        return 0;
    }
    int tmp=s;
    REP(i,m) FOR(j,i==0,9) if (0<=tmp-j && tmp-j<=9*(m-1-i)) {
        cout<<j;
        tmp-=j;
        break;
    }
    cout<<" ";
    tmp=s;
    REP(i,m) FORD(j,9,i==0) if (0<=tmp-j && tmp-j<=9*(m-1-i)) {
        cout<<j;
        tmp-=j;
        break;
    }
}