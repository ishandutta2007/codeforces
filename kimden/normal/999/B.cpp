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
    for(int i = 1; i <= n; ++i){
        if(n % i == 0){
            reverse(s.begin(), s.begin() + i);
        }
    }
    cout << s << endl;



}