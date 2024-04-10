#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define swap djaiofe
using namespace std;
const string del="automaton";
const string swap="array";
const string all="both";
const string none="need tree";
string s,t;
bool candel(void) {
    int id=0;
    FORE(it,t) {
        while (id<s.size() && s[id]!=*it) id++;
        if (id>=s.size()) return (false);
        id++;
    }
    return (true);
}
bool canswap(void) {
    string s=::s;
    string t=::t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return (s==t);
}
void process(void) {
    cin>>s>>t;
    if (candel()) {
        cout<<del;
        return;
    }
    if (canswap()) {
        cout<<swap;
        return;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if (candel()) cout<<all; else cout<<none;
}
int main(void) {
    process();
    return 0;
}