#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 10000;

int b[N+5];
int a[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    int x = 0, y = 0, z = 0, t;
    cout << "or 1 2" << endl;
    cin >> t;
    x += t;
    cout << "and 1 2" << endl;
    cin >> t;
    x += t;
    cout << "or 2 3" << endl;
    cin >> t;
    y += t;
    cout << "and 2 3" << endl;
    cin >> t;
    y += t;
    cout << "or 1 3" << endl;
    cin >> t;
    z += t;
    cout << "and 1 3" << endl;
    cin >> t;
    z += t;
    a[1] = (x + z - y)/2;
    a[2] = (x + y - z)/2;
    a[3] = (y + z - x)/2;
    for(int i=4; i<=n; i++){
        cout << "and 1 " << i << endl;
        cin >> t;
        a[i] += t;
        cout << "or 1 " << i << endl;
        cin >> t;
        a[i] += t;
        a[i] -= a[1];
    }
    sort(a+1, a+1+n);
    cout << "finish " << a[k] << endl;
    return 0;
}