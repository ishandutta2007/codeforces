#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int num[200050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    int a[200500];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    int val = 0;
    for(int i = 1; i <= 200000; i++) {
        if(num[i] > num[val]) val = i;
    }
    int index;
    for(int i = 1; i <= n; i++) {
        if(a[i] == val) index = i;
    }
    cout << n - num[val] << endl;
    for(int j = index - 1; j >= 1; j--) {
        if(a[j] == val) continue;
        if(a[j] < val) cout << "1 " << j << " " << j + 1 << endl;
        else cout << "2 " << j << " " << j + 1 << endl;
    }
    for(int j = index + 1; j <= n; j++) {
        if(a[j] == val) continue;
        if(a[j] < val) cout << "1 " << j << " " << j - 1 << endl;
        else cout << "2 " << j << " " << j - 1 << endl;
    }
    return 0;
}