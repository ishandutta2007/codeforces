#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T;
ll N;

int main() {
    cin >> N;
    vll a(N);
    ll res = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++)for(int j = i; j < N; j++)for(int k = j; k < N; k++){
        res=max(res,a[k]|a[i]|a[j]);
    }

    cout << res << "\n";
    return 0;
}