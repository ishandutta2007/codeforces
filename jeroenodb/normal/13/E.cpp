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
const int B = 250;
int to[mxN], cnt[mxN], last[mxN], jmp[mxN],n;
void update(int id) {
    int l =id*B,r = min(n,(id+1)*B);
    for(int i=r-1;i>=l;--i) {
        if(jmp[i]>=r) {
            to[i]=jmp[i],last[i]=i;
            cnt[i]=1;
        } else {
            to[i] = to[jmp[i]];
            last[i] = last[jmp[i]];
            cnt[i] = cnt[jmp[i]]+1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> n >> m;
    for(int i=0;i<n;++i) {
        cin >> jmp[i];
        jmp[i]+=i;
    }
    for(int i=0;i*B<n;++i) {
        update(i);
    }
    while(m--) {
        int t,a; cin >> t >> a,--a;
        if(t==0) {
            int b; cin >> b;
            jmp[a]=a+b;
            update(a/B);
        } else {
            int at = a,prv=-1,used=0;
            while(at<n) {
                prv=at;
                used+=cnt[at];
                at = to[at];
            }
            cout << last[prv]+1 << ' ' << used << '\n';
        }
    }
}