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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<pii> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(rall(p));
    cout << p[k - 1].first << endl;
    for(int i = 0; i < k; ++i){
        if(i){
            cout << " ";
        }
        cout << p[i].second + 1;
    }
    cout << endl;
}