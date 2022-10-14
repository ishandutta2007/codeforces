#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

typedef long long llint;

using namespace std;

llint n, m;

int main () {
    cin >> n >> m;
    if (n>62) cout << m; else cout << m % (1LL << n);
    return 0;
}