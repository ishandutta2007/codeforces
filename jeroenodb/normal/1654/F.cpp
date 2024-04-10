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
int main() {
    int n; cin >> n;
    string s; cin >> s;
    struct node {
        pi p = {oo,oo};
        int rnk=0;
    };
    vector<node> nds(1<<n);
    for(int i=0;i<(1<<n);++i) {
        nds[i].p = {s[i],s[i]};
    }
    vi ord(1<<n), nord(1<<n);
    iota(all(ord),0);
    vi cnt( max((1<<n) + 1,256));
    auto mysort = [&](auto key) {
        fill(all(cnt),0);
        for(auto i : ord) {
            cnt[key(i)+1]++;
        }
        partial_sum(all(cnt),cnt.begin());
        for(int i : ord) {
            nord[cnt[key(i)]++] = i;
        }
        swap(ord,nord);
    };
    auto rerank = [&]() {

        mysort([&](int i) {return nds[i].p.second;});
        mysort([&](int i) {return nds[i].p.first;});
        int prv = ord[0], rank=0;
        for(auto i : ord) {
            if(nds[i].p!=nds[prv].p) rank++;
            nds[i].rnk=rank;
            prv=i;
        }
    };
    for(int len=1;len<(1<<n);len*=2) {
        rerank();
        vector<node> newnds(1<<n);
        for(int i=0;i<1<<n;i+=2*len) {
            for(int j=0;j<len;++j) {
                auto& l = nds[i+j], r = nds[i+j+len];
                newnds[i+j].p = {l.rnk,r.rnk};
                newnds[i+j+len].p = {r.rnk,l.rnk};
            }
        }
        nds = move(newnds);
    }
    rerank();
    string res(1<<n,'?');
    for(int j=0;j<1<<n;++j) {
        if(nds[j].rnk==0) {
            for(int i=0;i<(1<<n);++i) {
                res[i^j]=s[i];
            }
            break;
        }
    }
    cout << res << '\n';
}