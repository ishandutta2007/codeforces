#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;
vector<VI> dp(20, VI(700006, -1));

const int MOD = 998244353;


void jebaj() {
    VI v = {1, 4, 9, 20, 41, 84, 169, 340, 681, 1364, 2729, 5460, 10921, 21844, 43689, 87380, 174761, 349524, 699049, 1398100};
    VI w;
    std::transform(v.begin(), v.end(), std::back_inserter(w), [](int a){return a+1;});
    v.insert(v.end(), w.begin(), w.end());
    sort(ALL(v));
    int n;
    cin >> n;
    cout << ((std::find(v.begin(), v.end(), n) == v.end()) ? 0 : 1) << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    //cin >> t;
    while (t--) {
        jebaj();
    }
    return 0;
}