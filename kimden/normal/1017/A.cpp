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
    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);
    v.resize(n);
    for(int i = 0; i < n; ++i){
        v[i] = i;
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    stable_sort(all(v), comp);
    for(int i = 0; i < n; ++i){
        if(v[i] == 0){
            cout << i + 1 << endl;
        }
    }


    return 0;
}