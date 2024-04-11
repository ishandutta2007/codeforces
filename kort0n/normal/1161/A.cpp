#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N, K;
int x[100050];
int last[100050];
int first[100500];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 1; i <= K; i++) cin >> x[i];
    for(int i = 1; i <= N; i++) {
        last[i] = 0;
        first[i] = K + 1;
    }
    for(int i = 1; i <= K; i++) {
        last[x[i]] = i;
    }
    for(int i = K; i >= 1; i--) {
        first[x[i]] = i;
    }
    for(int i = 1; i <= N; i++) {
        //cerr << i << " " << first[i] << " " << last[i] << endl;
    }
    int ans = 0;
    for(int from = 1; from <= N; from++) {
        for(int delta = -1; delta <= 1; delta++) {
            int end = from + delta;
            if(end < 1 || end > N) continue;
            //cerr << from << " " << end << endl;
            if(first[from] > last[end]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}