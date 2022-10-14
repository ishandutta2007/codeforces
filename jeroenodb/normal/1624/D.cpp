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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        array<int,26> cnt = {};
        for(auto c : s) cnt[c-'a']++;
        auto good = [&](int mid) {
            auto mycnt = cnt;
            for(int i=0;i<k;++i) {
                if(mid%2==1) {
                    // find middle character
                    bool found=false;
                    for(int j=0;j<26;++j) if(mycnt[j]%2==1) {
                        mycnt[j]--;
                        found =true;
                        break;
                    }
                    if(!found) {
                        auto& c = *max_element(all(mycnt));
                        if(c==0) return false;
                        c--;
                    }
                }
                int pairs = mid/2;
                for(auto& j : mycnt) {
                    int dif = min(pairs,j/2);
                    pairs-=dif;
                    j-=dif*2;
                }
                if(pairs) return false;
            }
            return true;
        };
        int lo=1,hi=n;
        while(lo<hi) {
            int mid = (lo+hi+1)/2;
            if(good(mid)) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        cout << lo << '\n';
    }
}