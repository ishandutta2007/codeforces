#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<bool> there(1000001, false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        there[a] = true;
    }
    int ans = 0;
    for(int i = 1; i <= 1000000; i++) {
        if(there[i]) {
            continue;
        }
        int now = 0;
        for(int j = i * 2; j <= 1000000; j+=i) {
            if(there[j]) {
                now = gcd(now, j);
            }
        }
        if(now == i) ++ans;
    }
    cout << ans;
}