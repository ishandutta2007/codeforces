#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll sum;
    ll n;
    cin >> n;
    sum = n * (n + 1) / 2;
    ll div;
    for(ll i = 2; ; i++){
        if(sum % i == 0){
            div = i;
            break;
        }
        if(i * i > sum){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    vector<ll> ans[2];
    for(int i = n; i >= 1; i--){
        if(i <= div){
            ans[0].push_back(i);
            div -= i;
        } else {
            ans[1].push_back(i);
        }
    }
    for(int i = 0; i < 2; i++){
        cout << ans[i].size() << " ";
        for(int k = 0; k < ans[i].size(); k++){
            cout << ans[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}