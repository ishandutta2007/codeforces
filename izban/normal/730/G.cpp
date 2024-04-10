#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define equal equalll
#define less lesss
typedef long long ll;
const int N = -1;
const long long INF = 1e9 + 19;

int n;
vector<pair<ll, ll>> answer;


bool go(ll st, ll len) {
    bool flag = 1; 
    for (auto seg: answer) {    
        //db2(st, len);
        //db2(seg.fr, seg.sc);
        flag &= seg.sc <= st || st + len <= seg.fr;
    }
    return flag;
}

void read() {
    scanf("%d", &n);
    vector<ll> st;
    st.pb(1);
    
    for (int i = 0; i < n; i++) {
        //cerr << "i: " << i << endl;
        ll tmr, len;
        scanf("%I64d%I64d", &tmr, &len);
        
        if (go(tmr, len)) {
            answer.pb(mp(tmr, tmr + len));
        }
        else {
            for (auto x: st)
                if (go(x, len)) {
                    answer.pb(mp(x, x + len));
                    break;
                }
        }
        st.pb(answer.back().sc);
        sort(all(st));
    }

    for (auto x: answer)
        printf("%I64d %I64d\n", x.fr, x.sc - 1);
}

void solve() {

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}