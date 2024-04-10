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
    int c,n; cin >> c >> n;
    vi cnt(c+1);
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        cnt[a]++;
    }
    vi l(c+1);
    for(int i=1;i<=c;++i) {
        if(cnt[i]) l[i]=i;
        else l[i] = l[i-1];
    }
    for(int my = 1;my<c;++my) {
        int sm = c;
        bool usedmy = false;
        int to=l[c];
        while(sm>0) {
            to = min(l[to],l[sm]);
            if(!usedmy and sm>=my and my>=to) {
                usedmy=true;
                sm-=my;
            } else {
                if(to==0) {
                    cout << my << '\n';
                    exit(0);
                }
                sm-=min(sm/to,cnt[to])*to;
                to--;
            }
        }
    }
    cout << "Greed is good\n";
}