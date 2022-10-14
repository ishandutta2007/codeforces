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
const int N = 41, K=10, oo = 1e9;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int n,k;
typedef bitset<40> state;
state msk[K], t[K], suf[K][N];
int nw[K];
state sortedseq[N];
bool sorted(const state& s,int c) {
    return sortedseq[c]==s;
}
bool rec(int i=0, state s=0, int c=0) {
    if(i==k) {
        return sorted(s,c);
    }
    int extra = nw[i], cur = (s&msk[i]).count();
    s&=~msk[i];
    for(int j=0;j<=extra;++j) {
        if(!rec(i+1,s|suf[i][cur+j],c+j)) return false;
    }
    return true;
}
int main() {
    cin >> n >> k;
    for(int i=0;i<k;++i) {
        int q; cin >> q;
        for(int j=0;j<q;++j) {
            int a; cin >> a,--a;
            msk[i][a]=true;
        }
        if(i) {
            t[i]|=t[i-1];
            nw[i] = ((~t[i-1])&msk[i]).count();
        } else nw[i] = msk[i].count();
        t[i]|=msk[i];
        suf[i][q]=msk[i];
        for(int j=q-1;j>=0;--j) {
            auto& cur = suf[i][j];
            cur =suf[i][j+1];
            cur[cur._Find_first()]=false;
        }
    }
    for(int i=1;i<=n;++i) {
        sortedseq[i] = sortedseq[i-1];
        sortedseq[i][n-i]=true;
    }
    if(n>1 and sortedseq[n]!=t[k-1]) {
        cout << "REJECTED\n";
    } else cout << (rec()?"ACCEPTED\n":"REJECTED\n");
}