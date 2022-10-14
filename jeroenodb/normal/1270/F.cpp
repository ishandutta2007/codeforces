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
const int B = 320;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
auto RND = rnd(0ULL, numeric_limits<size_t>().max());
const int MX = 1.1e8;
int dat[MX];
int *cnt = dat+(MX*3/4);

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    // string s;
    // for(int i=0;i<200000;++i) s.push_back(rnd('0','1'));
    int n = s.size();
    ll ans=0;

    for(int j=1;j<min(B,n+1);++j) {
        // count all things with factor len = j * (number of ones)
        int lazy=0;
        vi undo;
        for(auto i : s) {
            if( (++cnt[-lazy])==1) undo.push_back(-lazy);
            --lazy;
            if(i=='1') lazy+=j;
            ans+=cnt[-lazy];
        }
        for(auto i : undo) cnt[i]=0;
    }

    vi ones = {-1};
    for(int i=0;i<n;++i) {
        if(s[i]=='1') ones.push_back(i);
        // for all substrings ending at i
        int num=0;
        for(auto it = ones.rbegin();ones.rend()!=it;++it) {
            ++num;
            if(*it==-1) break;
            if(num*B>i+1) break;
            int minl = max(num*B, i - *it + 1), maxl = i - *(it+1);
            if(minl>maxl) continue;
            minl = (minl+num-1)/num, maxl/=num;
            ans+=max(0,maxl-minl+1);
        }
    }
    
    cout << ans << '\n';
}