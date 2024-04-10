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
    vvi cards(n,vi(n+1));
    for(auto& v : cards) {
        for(int i=0;i<n;++i) {
            int a; cin >> a;
            v[a]++;
        }
    }
    
    vvi ans;
    while(true) {
        vi res;
        res.reserve(n);
        bool done=true;
        for(int i=2;i<=n;++i) {
            if(cards[0][i]>=2) {
                done=false;
                res.push_back(i);
                break;
            }
        }
        if(res.empty()) res.push_back(1);
        for(int i=1;i<n;++i) {
            auto& v = cards[i];
            bool found=false;
            for(int dif = n-1;dif>=1;--dif) {
                int to = (i+dif)%n+1;
                if(to!=1) {
                    if(v[to]) {
                        res.push_back(to);
                        done=false;
                        found=true;
                        break;
                    }
                }
            }
            if(v[i+1]==n) {
                res.push_back(i+1);
                done=false;
            } else if(!found) {
                res.push_back(1);
            }
        }
        if(done) {
            break;
        }
        for(int i=0;i<n;++i) {
            cards[(i+1)%n][res[i]]++;
            cards[i][res[i]]--;
        }
        ans.push_back(res);
    }
    for(int r=n;r>=2;--r) {
        vi res;
        res.reserve(n);
        res.push_back(r);
        for(int i=1;i<n;++i) {
            auto& v = cards[i];
            for(int j=1;j<=n;++j) if(i!=j-1 and v[j]) {
                res.push_back(j);
                break;
            }
        }
        for(int i=0;i<n;++i) {
            cards[(i+1)%n][res[i]]++;
            cards[i][res[i]]--;
        }
        ans.push_back(res);
    }
    cout << ans.size() << '\n';
    for(auto v : ans ) {
        cout << v << '\n';
    }

}