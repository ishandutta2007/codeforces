#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<int> m, s;

bool comp(int i, int j){
    return m[i] < m[j];
}

int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    m.resize(n);
    s.resize(n);
    for(int i = 0; i < n; ++i){
        v[i] = i;
        cin >> m[i];
        cin >> s[i];
    }
    sort(all(v), comp);
    int ptr1 = 0, ptr2 = 0;
    ll sum = 0;
    while(ptr2 < n && m[v[ptr2]] < m[v[0]] + d){
        sum += s[v[ptr2]];
        ++ptr2;
    }
    ll ans = sum;
    for(int i = 1; i < n; ++i){
        sum -= s[v[i - 1]];
        while(ptr2 < n && m[v[ptr2]] < m[v[i]] + d){
            sum += s[v[ptr2]];
            ++ptr2;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}