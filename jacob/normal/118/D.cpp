#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
ll MOD = 100000000;

int main(void) {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    vector< vector<ll> > num1(n1+n2+1, vector<ll>(n1+1)), num2(n1+n2+1, vector<ll>(n1+1));
    num1[0][0] = 1;
    num2[0][0] = 1;
    for (int i = 1; i <= n1 + n2; i++) {
        for (int j = 1; j <= min(i, n1); j++) {
            for (int k = 1; k <= min(j, k1); k++) {
                num1[i][j] += num2[i-k][j-k];
                num1[i][j] %= MOD;
            }
        }
        for (int j = 0; j <= n1; j++) {
            for (int k = 1; k <= min(i, k2); k++) {
                num2[i][j] += num1[i-k][j];
                num2[i][j] %= MOD;
            }
        }
    }
    cout << (num1[n1+n2][n1] + num2[n1+n2][n1]) % MOD << endl;
    return 0;
}