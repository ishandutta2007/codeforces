#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;

namespace ahocorasick {
const int sigma = 26, mask = sigma-1;
const char firstc = 'a';
struct smallmap {
    int ar[sigma]={};

    int get(char to) {
        return ar[to-firstc];
    }
    void add(char to, int id) {
        ar[to-firstc] = id;
    }
};

const int mxN = 1.2e5+1, oo = 1e9;

smallmap trie[mxN]; int p=2;
int fail[mxN], output[mxN], depth[mxN],cnt[mxN];
vi marked[mxN];
vi occs[mxN];
void addword(const char* c, int id) {
    int at = 1;
    while(*c) {
        int tmp;
        if(!(tmp = trie[at].get(*c))) {
            trie[at].add(*c, p);
            depth[p] = depth[at]+1;
            trie[p] = smallmap();
            at = p++;
        } else {
            at = tmp;
        }
        c++;
    }
    marked[at].push_back(id);
}
queue<int> q;

int transition(int at, char c) {
    int tmp;
    while( (tmp = trie[at].get(c))==0) {
        at = fail[at];
    } 
    return tmp;
}
void makefail(int at, char c, int to) {
    while(true) {
        at = fail[at];
        int ans = trie[at].get(c);
        if(ans) {
            fail[to] = ans;
            output[to] = marked[ans].size()?ans:output[ans];
            break;
        }
    }
    q.push(to);
}

void update(int at) {
    for(int d=firstc;d<firstc+sigma;++d) {
        int to = trie[at].get(d);
        if(to) {
            makefail(at,d,to);
        }
    }
}

void construct() {
    // construct fail array
    bool doupdate[firstc+sigma]={};
    fail[1] = 1;
    int tmp;

    for(int c = firstc;c<firstc+sigma;++c) {
        if(!(tmp = trie[1].get(c))) {
            trie[1].add(c,1);
        } else {
            doupdate[c] = true;
            fail[tmp]=1;
        }
    }
    for(int c = firstc;c<firstc+sigma;++c) {
        if(doupdate[c]) {
            tmp = trie[1].get(c);
            update(tmp);
        }
    }
    while(!q.empty()) {
        update(q.front()); q.pop();
    }
}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int k; cin >> k;
    using namespace ahocorasick;
    trie[1] = smallmap();
    vi need(k);
    for(int i=0;i<k;++i) {
        cin >> need[i];
        string t; cin >> t;
        addword(t.c_str(),i);
    }
    construct();
    int n = s.size();
    int at = 1;
    vi firstpos(k,-1);
    vi ans(k,oo);
    for(int i=0;i<n;++i) {
        at = transition(at,s[i]);
        int o = at;
        if(marked[o].empty()) o = output[o];
        while(o>1) {
            auto id = marked[o].back();
            auto& v = occs[o];
            v.push_back(i-depth[o]);
            if(need[id]<=v.size()) {
                ans[id] = min(ans[id], i-v[v.size()-need[id]]);
            }
            
            o = output[o];
        }
    }
    for(auto i : ans) cout << (i==oo?-1:i) << '\n';

}