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
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    int ans=0;
    vi cnt(n+1);
    int bad=0;
    auto add = [&](int b) {
        cnt[b]++;
        if(cnt[b]==2) bad++;
    };
    auto remove = [&](int b) {
        cnt[b]--;
        if(cnt[b]==1) bad--;
    };
    for(int rep=0;rep<2;++rep) {
        vi ones;
        vi sufmx(n,1);
        for(int i=0;i<n;++i) if(a[i]==1) ones.push_back(i);
        ones.push_back(n);
        // find ....MX...1xxxxxx
        int prv=0;
        for(int k=0;k+1<ones.size();++k) {
            int mid = ones[k];
            int rb = ones[k+1];
            for(int j=mid+1;j<rb;++j) {
                sufmx[j] = max(sufmx[j-1],a[j]);
            }
            int l=mid, r=mid;
            cnt[1]++;
            int mx = 1;
            while(l>prv) {
                l--;
                mx = max(a[l],mx);
                if(r!=mid) remove(a[r--]);
                while(r-l+1<mx and r+1<rb) {
                    add(a[++r]);
                }
                add(a[l]);
                if(r-l+1==mx and !bad and sufmx[r]<mx) {
                    ans++;
                }
            }
            for(int j=prv;j<rb;++j) cnt[a[j]]=0;
            bad=0;
            prv=mid;
        }
        reverse(all(a));

    }
    ans+=count(all(a),1);
    cout << ans << '\n';
    
}