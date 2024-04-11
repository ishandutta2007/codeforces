#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define __V vector
#define vi __V<int>
#define pi pair<int, int>
using namespace std;
int n, m, k = 2, ans, v, rem;
__V<vi> g;
vi dp, dps, p;
//200009

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(n == 2) {
        cout << "2 2\n";
        cout << "1 2 2\n";
        return 0;
    }
    if(n == 3 && m == 2) {
        cout << "5 7\n";
        cout << "1 2 2\n";
        cout << "1 3 5\n";
        return 0;
    }
    if(n == 3 && m == 3) {
        cout << "5 7\n";
        cout << "1 2 2\n";
        cout << "1 3 5\n";
        cout << "2 3 24\n";
        return 0;
    }
    cout << "2 1000000007\n";
    cout << "1 " << n << " 2" << "\n";
    rem = 1000000005%(n-2);
    v = 1000000005/(n-2);
    for(int j = 2; j <= (n - 1); j++) {
        if(j == (n - 1)) {
               cout << 1 << " " << j << " " << (v+rem) << "\n";
               break;
        }
        cout << 1 << " " << j << " " << v << "\n";
    }
    k = n-1;
    if(k == m) return 0;
    for(int i = 2; i < n; i++)
    for(int j = i+1; j <= n; j++) {
        cout << i << " " << j << " " << (1000000000) << "\n";
        k += 1;
        if(k == m) { return 0;}
    }
}