#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll ans[100050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    if(k == 1) {
        cout << "YES" << endl;
        cout << n << endl;
        return 0;
    }
    ll sum = 0;
    for(ll i = 1; i <= k; i++) {
        ans[i] = i;
        sum += i;
    }
    if(sum > n) {
        cout << "NO" << endl;
        return 0;
    }
    ll val = (n - sum) / k;
    for(int i = 1; i <= k; i++) {
        ans[i] += val;
        sum += val;
    }
    int index = k;
    int limit = 1;
    while(true) {
        if(sum == n) break;
        //cerr << limit << " " << index << endl;
        if(limit == k) break;
        if(limit == index) index = k;
        if(ans[index-1] * 2 < ans[index]+1) {
            limit = index;
            continue;
        }
        ans[index]++;
        sum++;
        index--;
        if(sum == n) break;
    }
    if(sum != n) {
        cout << "NO" << endl;
        return 0;
    }
    /*
    for(int i = 0; i < (n-sum); i++) {
        ans[k-i]++;
    }
    */
    /*
    for(int i = 1; i < k; i++) {
        if(!((ans[i] < ans[i+1]) && (ans[i]*2 >= ans[i+1]))) {
            cerr << i << endl;
            cout << "NO" << endl;
            return 0;
        }
    }
    */
    cout << "YES" << endl;
    for(int i = 1; i <= k; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}