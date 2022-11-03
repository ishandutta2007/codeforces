#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<ll> a, b, c, d, v;

bool comp(int i, int j){
    ll sumi = a[i] + b[i] + c[i] + d[i];
    ll sumj = a[j] + b[j] + c[j] + d[j];
    if(sumi == sumj){
        return i < j;
    }
    return sumi > sumj;

}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<ll> v(4, 0);
    for(int i = 0; i < n; ++i){
        ++v[(a[i] - '0') * 2 + (b[i] - '0')];
    }
    ll ans = 0;
    ans += v[0] * v[2];
    ans += v[1] * v[2];
    ans += v[0] * v[3];
    cout << ans << endl;

    return 0;
}