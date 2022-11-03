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
    string s;
    cin >> s;
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i){
        switch(s[i]){
        case 'U': --y; break;
        case 'L': --x; break;
        case 'D': ++y; break;
        case 'R': ++x; break;
        }
    }
    cout << n - abs(x) - abs(y) << endl;
}