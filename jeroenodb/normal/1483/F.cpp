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

const int sigma = 26, mask = sigma-1;
struct smallmap {
    int ar[sigma]={};
    int get(char to) {
        return ar[to-'a'];
    }
    void add(char to, int id) {
        ar[to-'a'] = id;
    }
};
#ifdef LOCAL
const int mxN = 50+1, oo = 1e9;
#else
const int mxN = 1.1e6+1, oo = 1e9;
#endif

smallmap* trie = new smallmap[mxN]; int p=2;
int fail[mxN], output[mxN], depth[mxN];
bitset<mxN> marked;
int addword(const char* c) {
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
    marked[at] = true;
    return at;
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
const char firstc = 'a';
void update(int at) {
    for(int d=firstc;d<firstc+sigma;++d) {
        int to = trie[at].get(d);
        if(to) {
            makefail(at,d,to);
        }
    }
}
int him;
int outp(int at) {
    if(him!=at and marked[at]) return at;
    return output[at];
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
int found[mxN], cursubs = 0;
vi adj[mxN];
int in[mxN], out[mxN];
bool used[mxN];
namespace fenwick {
    int n;
    int fen[mxN];
    void update(int i, int val) {
        i++;
        while(i<=n) {
            fen[i]+=val;
            i+= i&-i;
        }
    }
    int sum(int i) {
        i++;
        int ans = 0;
        while(i) {
            ans+=fen[i];

            i&=i-1;
        }
        return ans;
    }
    int query(int l, int r) {
        return sum(r)-sum(l-1);
    }
}
struct mstack{
    int p = 0;
    int ar[mxN];
    int pop() {
        assert(p);
        return ar[--p];
    }
    void push(int a) {
        ar[p++] = a;
    }
    bool empty() {
        return p==0;
    }
} st;
int main() {
    int k; cin >> k;
    fenwick::n = k+1;
    trie[1] = smallmap();
    vector<string> words; words.reserve(k);
    vector<int> last(k);
    for(int i=0;i<k;++i) {
        string t; cin >> t;
        last[i] = addword(t.c_str());
        words.push_back(t);
    }
    construct();
    // make tree out of output links O(k) space and time
    for(int i : last) {
        adj[output[i]].push_back(i);
    }
    st.push(0);
    int cnt = 0;
    while(!st.empty()) {
        int at = st.pop();
        if(at<0) {
            if(at==-oo) {
                at = 0;
            }
            out[-at] = cnt-1;
            continue;
        }
        in[at] = cnt++;
        if(at) st.push(-at);
        else st.push(-oo);
        for(int to: adj[at]) {
            st.push(to);
        }
    }
    ll ans = 0;
    int l = 0;
    for(auto& w : words) {
        him = last[l++];
        int at = 1;
        for(int i=0;i<w.size();++i) {
            at = trie[at].get(w[i]);
            int me = outp(at);
            if(me) {
                if(!found[me]++) {
                    fenwick::update(in[me],1);
                    ans++;
                    used[me] = true;
                }
            }
            st.push(at);
        }
        int left = oo;
        while(!st.empty()) {
            at = st.pop();
            int me = outp(at);
            if(me) {
                int mylen = depth[me];
                if(left<=st.p-mylen+1) {
                    ans-=used[me];
                    used[me] = false;
                } 
                found[me]--;
                left = min(left, st.p-mylen+1);
                if(found[me]==0) {
                    if(in[me]!=out[me] and fenwick::query(in[me]+1, out[me])) {
                        ans-=used[me];
                        used[me] = false;
                    }
                    found[me] = -1;
                }
            }
        }
        st.p = w.size();
        while(!st.empty()) {
            at = st.pop();
            int me = outp(at);
            if(me) { 
                if(found[me]==-1) {
                    used[me]=false;
                    found[me] = 0;
                    fenwick::update(in[me],-1);
                }
            }
        }
    }
    cout << ans << '\n';
    
    
    

}