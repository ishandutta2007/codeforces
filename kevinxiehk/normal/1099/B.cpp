#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int main() {
    int n;
    cin >> n;
    int t = sqrt(n);
    if(t * t == n) {
        cout << t * 2 << '\n';
    }
    else if(t * (t + 1) >= n) {
        cout << t * 2 + 1 << '\n';
    }
    else cout << t * 2 + 2 << '\n';
    return 0;
}