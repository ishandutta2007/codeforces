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
    int n,m,k=0; cin >> n >> m;
    vvi boxes(n);
    vi sz;
    for(auto& i : boxes) {
        int s; cin >> s;
        sz.push_back(s);
        k+=s;
        i.resize(s);
        for(auto& j : i) cin >> j;
        sort(all(i));
    }
    int mid = k/n;
    int high = k-mid*n, low = n-high;
    vector<int> big,small;
    vector<array<int,3>> ans;
    auto check = [&](int i) {
        if(sz[i]==mid and low) low--;
        else if(sz[i]==mid+1 and high) high--;
        else return false;
        return true;
    };
    for(int i=0;i<n;++i) {
        if(check(i)) continue;
        if(sz[i]>=mid+1) {
            big.push_back(i);
        } else small.push_back(i);
    }
    vector<set<int>> extra(n);
    for(auto i = big.begin(),j = small.begin(); i!=big.end() and j!=small.end();) {
        auto& v = boxes[*i];
        for(int o=0;o<sz[*i];++o) {
            swap(v[o],v.back());
            if(!binary_search(all(boxes[*j]),v.back()) and !extra[*j].count(v.back())) {
                ans.push_back({*i+1,*j+1,v.back()});
                extra[*j].insert(v.back());
                v.pop_back();
                sz[*i]--,sz[*j]++;
                bool bad=false;
                if(check(*i)) i++,bad=true;
                if(check(*j)) j++, bad=true;
                if(bad) break;
                --o;
            } else swap(v[o],v.back());
        }
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

}