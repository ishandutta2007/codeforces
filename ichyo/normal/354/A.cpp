#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int N;
    ll L, R, QL, QR;
    while(cin >> N >> L >> R >> QL >> QR){
        vector<ll> w(N);
        REP(i, N) cin >> w[i];
        vector<ll> sumL(N + 1), sumR(N + 1);
        for(int i = 0; i < N; i++){
            sumL[i + 1] = sumL[i] + L * w[i];
        }
        for(int i = 0; i < N; i++){
            sumR[i + 1] = sumR[i] + R * w[N - 1 - i];
        }
        ll ans = 10000000000000000LL;
        for(int left = 0; left <= N; left++){
            int right = N - left;
            ll sum = 0;
            if(right - left - 1 > 0) sum += QR * (right - left - 1);
            if(left - right - 1 > 0) sum += QL * (left - right - 1);
            sum += sumL[left];
            sum += sumR[right];
            ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}