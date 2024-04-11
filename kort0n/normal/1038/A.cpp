#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    string s;
    int n, k;
    cin >> n >> k >> s;
    int number[30];
    for(int i = 0; i < 29; i++){
        number[i] = 0;
    }
    for(int i = 0; i < s.size(); i++){
        number[(int)s[i] - 64]++;
    }
    int ans = INF;
    for(int i = 1; i <= k; i++){
        ans = min(ans, number[i]);
    }
    cout << ans * k << endl;
    return 0;
}