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
int main() {
    int t; cin >> t;
    while(t--) {
        int n,x; cin >> n >> x;
        vector<pair<int,int>> a(n);
        for(auto& p: a) {
            cin >> p.first;
            p.second= 1;
        }
        ll ans = 0;
        int i = 0;
        while(i!=a.size()) {
            if(a[i].first%x) {
                break;
            } else {
                a.push_back({a[i].first/x,x*a[i].second});
            }
            ++i;
        }

        for(auto p: a) {
            ans+= p.first*p.second;
        }
        print(ans);
    
    }
}