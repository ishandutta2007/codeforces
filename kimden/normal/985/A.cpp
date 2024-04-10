#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    vector<int> a(n / 2);
    for(int i = 0; i < n / 2; ++i){
        cin >> a[i];
        --a[i];
    }
    sort(all(a));
    for(int i = 0; i < n / 2; ++i){
        ans1 += abs(a[i] - 2 * i);
        ans2 += abs(a[i] - 2 * i - 1);
    }
    cout << min(ans1, ans2) << endl;


}