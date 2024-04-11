#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    vector<ll> in[2];
    for(int i = 0; i < 2; i++){
        for(int k = 0; k < n; k++){
            ll a;
            cin >> a;
            in[i].push_back(a);
        }
        in[i].push_back(-1000);
        sort(in[i].begin(), in[i].end());
    }
    ll ans = 0;
    for(int time = 0; time < 2 * n; time++){
        int index;
        if(in[0].back() >= in[1].back()){
            index = 0;
        } else {
            index = 1;
        }
        ll value = in[index].back();
        in[index].pop_back();
        if((index % 2) != (time % 2)){
            continue;
        }
        ans += ((index % 2) * (-2) + 1)  * value;
    }
    cout << ans << endl;
    return 0;
}