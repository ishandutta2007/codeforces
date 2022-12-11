#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int rmax = 20;

struct node 
{
    int to[26];
    int link;
    ll cnt;
    node()
    {
        cnt = 0;
        link = -1;
        for (int i = 0; i < 26; ++i) {
            to[i] = -1;
        }
    }
};

struct trie 
{
    ll get(const string& s)
    {
        int curr = 0;
        ll ans = 0;
        for (int i = 0; i < sz(s); ++i) {
            curr = t[curr].to[s[i] - 'a'];
            ans += t[curr].cnt;
        }
        return ans;
    }
    void add(const string& s)
    {
        int curr = 0;
        for (int i = 0; i < sz(s); ++i) {
            if (t[curr].to[s[i] - 'a'] == -1) {
                t[curr].to[s[i] - 'a'] = sz(t);
                t.pb(node());
            }
            curr = t[curr].to[s[i] - 'a'];
        }
        ++t[curr].cnt;
    }
    void get_links()
    {
        queue<int> q;
        t[0].link = 0;
        for (int i = 0; i < 26; ++i) {
            if (t[0].to[i] == -1) {
                t[0].to[i] = 0;
            }
        }
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            t[v].cnt += t[t[v].link].cnt;
            for (int i = 0; i < 26; ++i) {
                int to = t[v].to[i];
                if (to != -1 && t[to].link == -1) {
                    if (v == 0) {
                        t[to].link = 0;
                    } else {
                        t[to].link = t[t[v].link].to[i];
                    }
                    q.push(to);
                }
                if (to == -1) {
                    t[v].to[i] = t[t[v].link].to[i];
                }
            }
        }
    }
    trie() {}
    trie(const vector<string>& words1, const vector<string>& words2)
    {
        words.resize(sz(words1) + sz(words2));
        int pos = 0;
        for (int i = 0; i < sz(words1); ++i) {
            words[pos++] = words1[i];
        }
        for (int i = 0; i < sz(words2); ++i) {
            words[pos++] = words2[i];
        }
        t.pb(node());
        for (int i = 0; i < sz(words); ++i) {
            add(words[i]);
        }
        get_links();
    }
    vector<string> words;
    vector<node> t;
};

struct aho
{
    trie m[rmax];
    ll get(const string& s)
    {
        ll ans = 0;
        for (int i = 0; i < rmax; ++i) {
            if (!m[i].words.empty()) {
                ans += m[i].get(s);
            }
        }
        return ans;
    }
    void add(const string& s)
    {
        trie curr({}, {s});
        for (int pos = 0; ; ++pos) {
            if (m[pos].words.empty()) {
                m[pos] = curr;
                break;
            }
            curr = trie(curr.words, m[pos].words);
            m[pos].words = {};
            m[pos].t = {};
        }
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    
    aho add, del;
    
    while (q--) {
        int type;
        cin >> type;
        string s;
        cin >> s;
        if (type == 1) {
            add.add(s);
        } else if (type == 2) {
            del.add(s);
        } else {
            cout << add.get(s) - del.get(s) << "\n";
            cout.flush();
        }
    }

}