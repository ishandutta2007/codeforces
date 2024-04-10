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
const int mxN = 60e5+1, oo = 1e9;

struct trie {
    int to[2] = {};
};
trie tr[mxN];
int pp = 1;
void insert(int a, int i) {
    auto at = tr;
    for(int j=29;j>=0;--j) {
        int bt = a>>j & 1;
        if(!at->to[bt]) {
            tr[pp] =  trie();
            at->to[bt]=pp++;
        }
        at = tr+at->to[bt];
    }
    at->to[0] = i;
}
vi a;
int k;
vi ans;
typedef vi::iterator IT;
void best(IT l, IT r) {
    pp=1;
    tr[0] = trie();
    for(auto i =l;i!=r;++i) {
        insert(a[*i],*i);
    }
    for(auto i = l;i!=r;++i) {
        auto at = tr;
        auto cur = a[*i];
        int dif=0;
        for(int j=29;j>=0;--j) {
            int bt = (cur>>j & 1) ^ 1;
            if(!at->to[bt]) {
                bt=!bt;
            } else dif|=1<<j;
            at = tr+at->to[bt];
        }
        if(dif>=k) {
            ans.push_back(*i + 1);
            ans.push_back(at->to[0] + 1);
            return;
        }
    }
    ans.push_back(*l+1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n >> k;
    if(k==0) {
        cout << n << "\n";
        for(int i=1;i<=n;++i) cout << i << ' ';
        exit(0);
    }
    a.resize(n); for(auto& i : a) cin >> i;
    vi ord(n);
    iota(all(ord),0);
    sort(all(ord),[&](int i,int j){return a[i]<a[j];});
    
    int ptwo = 1;
    while(ptwo<k) ptwo*=2;
    const int ON = (1<<30)-1;
    int mask = ON^(ptwo-1);
    auto prev = ord.begin();
    for(auto it = ord.begin();it!=ord.end();++it) {
        if( (a[*it]^a[*prev])&mask)  {
            best(prev,it);
            prev=it;
        }
    }
    best(prev,ord.end());
    if(ans.size()==1) {
        cout << "-1\n";
    } else cout << ans.size() << '\n' << ans << '\n';
}