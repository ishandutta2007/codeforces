#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
string s;
vector<int> pos;
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin>>s;
    REP(i,s.size()) if ((s[i]-'0')%2==0) pos.push_back(i);
    if (pos.empty()) cout<<-1<<endl;
    else {
        REP(i,(int)pos.size()-1) if (s[pos[i]]<s[s.size()-1]) {
            swap(s[pos[i]],s[s.size()-1]);
            cout<<s<<endl;
            return 0;
        }
        swap(s[s.size()-1],s[pos[pos.size()-1]]);
        cout<<s<<endl;
    }
    return 0;
}