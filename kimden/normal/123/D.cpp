#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct SuffixAutomaton {
    int last;
    vector<int> len;
    vector<int> link;
    vector<map<char, int>> g;
    vector<int> cnt;

    SuffixAutomaton() {
        last = 0;
        len.push_back(0);
        link.push_back(-1);
        g.resize(1);
        cnt.push_back(0);
    }

    void add(string s){
        for(int i = 0; i < s.length(); ++i){
            add(s[i]);
        }
    }

    void add(char c){
        int cur = len.size();
        len.push_back(len[last] + 1);
        cnt.push_back(1);
        g.push_back(map<char, int>());
        link.push_back(-1);
        int p = last;
        while(p >= 0){
            if(g[p].count(c)){
                break;
            }
            g[p][c] = cur;
            p = link[p];
        }
        if(p == -1){
            link[cur] = 0;
            last = cur;
            return;
        }
        int q = g[p][c];
        if(len[q] == 1 + len[p]){
            link[cur] = q;
            last = cur;
            return;
        }
        int clone = len.size();
        len.push_back(len[p] + 1);
        g.push_back(g[q]);
        cnt.push_back(0);
        link.push_back(link[q]);
        link[q] = clone;
        link[cur] = clone;
        while(p >= 0){
            if(g[p].count(c) && g[p][c] == q){
                g[p][c] = clone;
            }else{
                break;
            }
            p = link[p];
        }
        last = cur;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    SuffixAutomaton sa;
    sa.add(s);
    vector<pii> w;
    for(int i = 0; i < sa.len.size(); ++i){
        w.push_back({-sa.len[i], i});
    }
    sort(w.begin(), w.end());
    for(int i = 0; i < sa.len.size(); ++i){
        if(sa.link[w[i].second] >= 0) {
            sa.cnt[sa.link[w[i].second]] += sa.cnt[w[i].second];
        }
    }
    ll ans = 0;
    for(int i = 1; i < sa.len.size(); ++i){
        ans += (sa.len[i] - sa.len[sa.link[i]]) * 1LL * (sa.cnt[i] * 1LL * (sa.cnt[i] + 1)) / 2LL;
    }
    cout << ans << endl;
}