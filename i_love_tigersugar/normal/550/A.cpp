#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const string yes="YES";
const string no="NO";
string s;
int n;
vector<int> ab,ba;
int main(void) {
    cin>>s;
    n=s.size();
    REP(i,n-1) {
        if (s[i]=='A' && s[i+1]=='B') ab.push_back(i);
        if (s[i]=='B' && s[i+1]=='A') ba.push_back(i);
    }
    FORE(it,ab) FORE(jt,ba) {
        if (*it==*jt-1 || *it==*jt || *it==*jt+1) continue;
        cout<<yes<<endl;
        return 0;
    }
    cout<<no<<endl;
    return 0;
}