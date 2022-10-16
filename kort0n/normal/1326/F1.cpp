#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
ll len;
ll dp[1<<14][1<<8][14];
string field[20];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    len = N / 2 + 1;
    len--;
    for(int i = 0; i < N; i++) cin >> field[i];
    for(int i = 0; i < N; i++) {
        dp[1<<i][0][i] = 1;
    }
    for(int bits = 1; bits < (1 << N); bits++) {
        int num = __builtin_popcount(bits);
        num--;
        if(num >= len) continue;
        for(int before = 0; before < N; before++) {
            if(!(bits & (1 << before))) continue;
            for(int after = 0; after < N; after++) {
                if(bits & (1 << after)) continue;
                for(int str = 0; str < (1 << num); str++) {
                    int newstr = str;
                    if(field[before][after] == '1') newstr += (1 << num);
                    //cerr << bits << " " << bitset<5>(str) << " " << before << " -> " << (bits | (1 << after)) << " " << bitset<5>(newstr) << " " << after << endl;
                    //cerr << dp[bits][str][before] << endl;
                    dp[bits | (1<<after)][newstr][after] += dp[bits][str][before];
                }
            }
        }
    }
    /*
    for(int i = 0; i < (1 << N); i++) {
        int ans = 0;
        for(int j = 0; j < N; j++) {
            ans += dp[(1 << N) - 1][i][j];
        }
        cerr << ans << " ";
    }
    */
    vector<ll> ans(1 << (N - 1));
    for(int bits = 0; bits < (1 << N); bits++) {
        if(__builtin_popcount(bits) != len + 1) continue;
        for(int c = 0; c < N; c++) {
            if(!(bits & (1 << c))) continue;
            int sub = (1 << N) - 1;
            sub ^= bits;
            sub |= (1 << c);
            int len2 = __builtin_popcount(sub) - 1;
            //cerr << bitset<5>(bits) << " " << bitset<5>(sub) << " " << c << " " << len << " " << len2 << endl;
            for(int str1 = 0; str1 < (1 << len); str1++) {
                if(dp[bits][str1][c] == 0) continue;
                int tmp1 = 0;
                for(int i = 0; i < len; i++) {
                    if(str1 & (1 << i)) tmp1 += (1 << i);
                }
                for(int str2 = 0; str2 < (1 << len2); str2++) {
                    int tmp = tmp1;
                    for(int i = 0; i < len2; i++) {
                        if(str2 & (1 << (len2-1-i))) tmp += (1 << (len+i));
                    }
                    ans[tmp] += dp[bits][str1][c] * dp[sub][str2][c];
                }
            }
        }
    }
    for(int i = 0; i < (1 << (N-1)); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}