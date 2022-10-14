#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x)
namespace {
template<class T1, class T2> void prin(const pair<T1,T2>& x);
template<class T> void prin(const vector<T>& x);
template<class T> void prin(const T& x) {cout << x;}
template<class H, class... T> void prin(const H& h, const T&... t) {prin(h); prin(' '); prin(t...); }
template<class T1, class T2> void prin(const pair<T1,T2>& x) {prin(x.first,' ',x.second);}
template<class T> void prin(const vector<T>& x) {for(int i=0;i<(int)x.size();++i) prin(i==0?"":" ",x[i]);}
template<class... T> void print(const T&... t) {prin(t..., "\n"); }
#define debug(x) cout << #x << ": "; print(x)
}
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int store=1e6 + 1;
int m[store] = {};

bitset<store> sieve={};
int factor[store] = {};
int loops= 0;
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makesieve();
    // for(int i=1;i<store;++i) {
    //         int odd=1;
    //         int cur = i;
    //         set<int> s;
    //         while(cur!=1) {
    //             int f = factor[cur];
    //             if(!s.insert(f).second) {
    //                 f=f;
    //             }
    //             bool yes = true;
    //             cur/=f;
    //             while(factor[cur] == f) {
    //                 yes = !yes;
    //                 cur/=f;
    //             }
    //             if(yes) odd*=f;
    //         }
    // }
    // debug(loops);
    // cout << primes.size() << endl;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        vector<int> used;
        for(int j=0 ;j<n;++j) {
            int odd=1;
            int cur; cin >> cur;
            while(cur!=1) {
                int f = factor[cur];
                bool yes = true;
                cur/=f;
                while(factor[cur] == f) {
                    yes = !yes;
                    cur/=f;
                }
                if(yes) odd*=f;
            }
            if(++m[odd]==1) {
                used.push_back(odd);
            }
        }
        int anszero = 0;
        int anselse = 0;
        int sq= 0 ;
        for(int i:used) {
            anszero = max(anszero, m[i]);
            if(m[i]%2==0 or i==1) {
                sq+=m[i];
            } 
            if(m[i]%2==1 and i!=1) {
                anselse = max(anselse, m[i]);
            }
            m[i] = 0;
        }
        anselse = max(sq,anselse);
        
        int q; cin >> q;
        while(q--) {
            ll cur; cin >> cur;
            if(cur!=0) {
                print(anselse);
            } else {
                print(anszero);
            }
        }
    }
}