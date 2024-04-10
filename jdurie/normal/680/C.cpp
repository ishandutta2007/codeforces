#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

bool isFactor(int k) {
    cout << k << endl;
    string resp;
    cin >> resp;
    return resp[0] == 'y';
}

bool prime[100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(prime, 100, true);
    for(int i = 2; i < 50; ++i) if(prime[i])
        for(int j = i * i; j < 50; j += i) prime[j] = false;
    int ct = 0;
    for(int i = 2; i < 50; ++i) if(prime[i]) {
        if(isFactor(i)) {
            ct++;
            if(ct == 2) break;
            if(i * i <= 100 && isFactor(i * i)) {
                ct++;
                break;
            }
        }
    }
    cout << (ct == 2 ? "composite\n" : "prime\n");
}