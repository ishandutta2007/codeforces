#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 1e9 + 10;

long long cal(long long n, long long use) {
    long long m = n / use;
    return use * m * (m - 1) / 2 + m;
}
int main() {
    int n;
    cin >> n;
    set<long long> ans;
    for(int i = 1; i * i <= n; i++) if (n % i == 0){ 
        ans.insert(cal(n, i));
        ans.insert(cal(n, n / i));
    }
    for(auto x : ans) cout << x << " ";
}