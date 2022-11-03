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
    vector<int> a(n);
    int c = -1;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(i){
            int b = abs(a[i] - a[i - 1]);
            if(b != 1){
                if(b == 0 || (c != -1 && c != b)){
                    cout << "NO" << endl;
                    return 0;
                }
                if(c == -1){
                    c = b;
                }
            }
        }
    }
    if(c == -1){
        c = 1;
    }
    int r = 0;
    for(int i = 1; i < n; ++i){
        int b = abs(a[i] - a[i - 1]);
        if(b == 1){
            if(max(a[i], a[i - 1]) % c == 1){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        r = max(r, (a[i] - 1) / c + 1);
    }
    cout << "YES\n" << r << " " << c << endl;




}