#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
string s,t;
int prefix(const string &s,const string &t) {
    REP(i,min(s.size(),t.size())) if (s[i]!=t[i]) return (i);
    return (min(s.size(),t.size()));
}
int suffix(string s,string t) {
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    return (prefix(s,t));
}
bool canMatch(const string &s,const string &t) {
    return (prefix(s,t)+suffix(s,t)>=min(s.size(),t.size()));
}
int main(void) {
    ios::sync_with_stdio(false);
    cin>>s>>s>>t;
    REP(i,s.size()) if (s[i]!=t[i]) {
        string a,b;
        a=s.substr(0,i);
        a.push_back(t[i]);
        a+=s.substr(i,s.size());
        b=t.substr(0,i);
        b.push_back(s[i]);
        b+=t.substr(i,t.size());
        printf("%d\n",canMatch(a,t)+canMatch(b,s));
        return 0;
    }
    assert(false);
}