#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    vector<ll> a;
    ll sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll in;
        cin >> in;
        sum += abs(in);
        a.push_back(in);
    }
    if(n == 1){
        cout << a[0] << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    if(a[0] > 0){
        cout << sum - 2 * a[0] << endl;
        return 0;
    }
    if(a[n - 1] < 0){
        cout << sum+ 2 * a[n - 1] << endl;
        return 0;
    }
    cout << sum << endl;
    return 0;
}