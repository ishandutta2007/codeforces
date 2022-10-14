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
const int mxN = 1e5+1, oo = 1e9;
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

const int mxN = 2.5e5+1, oo = 1e9;

smallmap* trie = new smallmap[mxN]; int p=2;
int fail[mxN], output[mxN], depth[mxN],cnt[mxN],ending[mxN];
bitset<mxN> marked;
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
    marked[at]=true;
    cnt[at]++;
    ending[at]++;
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
            output[to] = marked[ans]?ans:output[ans];
            break;
        }
    }
    q.push(to);
}

void update(int at) {
    cnt[at] += cnt[output[at]];
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
    using namespace ahocorasick;
    string t; cin >> t;
    int m = t.size(),n;
    cin >> n;
    for(int i=0;i<n;++i) {
        string s; cin >> s;
        addword(s.c_str(),-1);
    }
    construct();
    vi occs(m+1);
    int at = 1;
    ll ans=0;
    for(int i=0;i<m;++i) {
        at = transition(at,t[i]);
        occs[i+1] = cnt[at];
        int to = marked[at]?at:output[at];
        while(to>1) {
            int d = depth[to];
            ans+=occs[i+1-d]*ll(ending[to]);
            to = output[to];
        }
    }
    cout << ans << '\n';
}