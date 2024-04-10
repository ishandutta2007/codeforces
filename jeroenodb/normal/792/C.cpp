#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef vector<int> vi;
int main() {
    string n; cin >> n;
    int want = 0;
    for(auto& i : n) want+=i-'0';
    want %=3;
    string res="";

    auto better = [&](string s) {
        if(s=="") return;
        int i=0;
        while(i<(int)s.size()-1 and s[i]=='0') ++i;
        s=s.substr(i);
        if(res.size()<s.size()) res=s;
    };

    if(want==0) better(n);

    vi cnt[3] = {};
    for(int i=0;i<n.size();++i) {
        cnt[(n[i]-'0')%3].push_back(i);
    }

    if(cnt[want].size()) {
        string s = n;
        s.erase(s.begin()+cnt[want].back());
        better(s);
    }

    int notwant = want==2?1:2;
    if(cnt[notwant].size()>=2) {
        int b = cnt[notwant].back(), a = cnt[notwant].end()[-2];
        string s = n;
        s.erase(s.begin()+b), s.erase(s.begin()+a);
        better(s);
    }
    if(res!="") {
        cout << res << '\n';
    } else cout << "-1\n";

}