#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define inf 2e18


const int K = 26;

struct Vertex {
    int next[K];
    int leaf = -1;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int exit = -1;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s, int index) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = index;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

int get_exit(int v) {
    if(t[v].exit == -1) {
        if(v == 0 || t[v].p == 0)
            t[v].exit = 0;
        else {
            int link = get_link(v);
            if(t[link].leaf != -1)
                t[v].exit = link;
            else
                t[v].exit = get_exit(link);
        }
    }
    return t[v].exit;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);

    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> indices(q, vector<int>());
    vector<string> queries(q);
    vector<int> req(q);

    for(int i = 0; i < q; ++i) {
        cin >> req[i] >> queries[i];
        add_string(queries[i], i);
    }

    int cur = 0;
    for(int i = 0; i < s.length(); ++i) {
        cur = go(cur, s[i]);
        if(t[cur].leaf != -1)
            indices[t[cur].leaf].push_back(i);
        int temp = cur;
        while(get_exit(temp) != 0) {
            temp = get_exit(temp);
            indices[t[temp].leaf].push_back(i);
        }
    }

    for(int i = 0; i < q; ++i) {
        if(req[i] > indices[i].size()) {
            cout << "-1" << endl;
        } else {
            int ans = s.length();
            for(int j = req[i] - 1; j < indices[i].size(); ++j) {
                ans = min(ans, indices[i][j] - indices[i][j - req[i] + 1] + (int)queries[i].length());
            }
            cout << ans << endl;
        }
    }

    return 0;
}