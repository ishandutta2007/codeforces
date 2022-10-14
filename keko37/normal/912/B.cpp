#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef long long llint;

llint n, k;

int main () {
    cin >> n >> k;
    llint pot=1;
    while (pot<=n) pot*=2;
    pot/=2;
    if (k>1) cout << pot*2-1; else cout << n;
    return 0;
}