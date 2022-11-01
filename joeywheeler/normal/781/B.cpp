#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
pair<string,string> c[1005];
string ans[1005];
multiset<string> m;
set<string> used;

map<string,vector<int> > mp;
set<int> sn1; set<string> sn2;

void go(int i);

void go2(string s) {
    if (sn2.count(s)) return;
    sn2.insert(s);
    for (int i : mp[s]) go(i);
}

void go(int i) {
    if (sn1.count(i)) return;
    sn1.insert(i);
    if (ans[i] == "") {
        string s, t; tie(s,t) = c[i];
        if (used.count(s)) ans[i] = t;
        else ans[i] = s;
        used.insert(ans[i]);
    }
    go2(ans[i]);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        string a, b;
        cin >> a >> b;
        string s = a.substr(0,3), t = a.substr(0,2) + b[0];
        //cout << s << " " << t << "\n";

        mp[s].push_back(i);
        mp[t].push_back(i);

        c[i] = make_pair(s,t);

        if (m.count(s) < 2) m.insert(s);
    }
    FO(i,0,n) {
        string s, t; tie(s,t) = c[i];
        if (m.count(s) > 1) {
            ans[i] = t;
            used.insert(ans[i]);
        }
    }
    FO(i,0,n) if (ans[i] != "") {
        go(i);
    }

    FO(i,0,n) if (ans[i] == "") {
        string s, t; tie(s,t) = c[i];
        go(i);
    }

    FO(i,0,n) FO(j,0,i) if (ans[i] == ans[j]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    FO(i,0,n) cout << ans[i] << "\n";
}