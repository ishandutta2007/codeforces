#include<bits/stdc++.h>
#define MAX   2000200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string noAnswer="Palindromic tree is better than splay tree";
bool notPrime[MAX];
int cntPrime[MAX],cntPalin[MAX];
bool isPalin(int x) {
    string s;
    while (x>0) {
        s.push_back('0'+x%10);
        x/=10;
    }
    REP(i,s.size()/2) if (s[i]!=s[s.size()-1-i]) return (false);
    return (true);
}
void prepare(void) {
    REP(i,2) notPrime[i]=true;
    FOR(i,2,MAX-1) if (!notPrime[i])
        for (int j=2*i;j<MAX;j=j+i) notPrime[j]=true;
    FOR(i,1,MAX-1) cntPrime[i]=cntPrime[i-1]+(!notPrime[i]);
    FOR(i,1,MAX-1) cntPalin[i]=cntPalin[i-1]+isPalin(i);
}
void process(void) {
    int p,q;
    cin>>p>>q;
    int res=-1;
    FOR(i,1,MAX-1) if (1LL*cntPrime[i]*q<=1LL*cntPalin[i]*p) res=i;
    if (res<0) cout<<noAnswer<<endl;
    else cout<<res<<endl;
}
int main(void) {
    prepare();
    process();
    return 0;
}