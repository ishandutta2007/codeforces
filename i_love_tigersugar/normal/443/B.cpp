#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
bool repeat(const string &s) {
    if (s.size()&1) return (false);
    int n=s.size()>>1;
    REP(i,n) if (s[i]!=s[i+n] && s[i+n]!='?') return (false);
    return (true);
}
int main(void) {
    string s;
    int k;
    cin>>s>>k;
    REP(zz,k) s.push_back('?');
    int n=s.size();
    int res=0;
    REP(i,n) FOR(j,i,n-1) if (res<j-i+1 && repeat(s.substr(i,j-i+1))) res=j-i+1;
    cout<<res;
    return 0;
}