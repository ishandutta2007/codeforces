#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    int a, b, c, d, e, p, m;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s >> p >> m >> a >> b >> c >> d >> e;
        v[i] = {p * 100 - m * 50 + a + b + c + d + e, s};
    }
    sort(rall(v));
    cout << v[0].second << endl;
}