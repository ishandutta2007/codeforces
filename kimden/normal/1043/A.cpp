#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    int o = (2 * sum)/ n + 1;
    o = max(o, mx);
    cout << o << endl;




}