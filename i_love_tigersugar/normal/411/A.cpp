#include<bits/stdc++.h>
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int main(void) {
    ios::sync_with_stdio(true);
    string s;
    cin >> s;
    bool sm=false;
    bool la=false;
    bool no=false;
    FORE(it,s) {
        if ('a'<=*it && *it<='z') sm=true;
        if ('A'<=*it && *it<='Z') la=true;
        if ('0'<=*it && *it<='9') no=true;
    }
    if (sm && la && no && s.size()>=5) cout << "Correct"; else cout << "Too weak";
    return 0;
}