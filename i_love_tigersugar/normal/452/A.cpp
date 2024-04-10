#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const string name[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
string ans;
bool ok(string a,string b) {
    if (a.size()!=b.size()) return (false);
    REP(i,a.size()) if (a[i]!='.' && a[i]!=b[i]) return (false);
    return (true);
}
int main(void) {
    cin>>ans>>ans;
    REP(i,8) if (ok(ans,name[i])) {
        cout<<name[i];
        return 0;
    }
}