#include<bits/stdc++.h>
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const string tmp="AHIMOTUVWXY";
using namespace std;
bool ok(char x) {
    FORE(it,tmp) if (*it==x) return (true);
    return (false);
}
int main(void) {
    string s,t;
    cin >> s;
    FORE(it,s) if (!ok(*it)) {
        cout<< "NO";
        return 0;
    }
    t=s;
    reverse(t.begin(),t.end());
    if (t==s) cout << "YES"; else cout << "NO";
    return 0;
}