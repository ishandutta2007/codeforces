#include <bits/stdc++.h>
using namespace std;

main(){
    int n, m, k, r;
    cin >> n >> m;
    k = m;
    for (int i = 0; i < n; ++i){
        k /= 2;
    }
    for (int i = 0; i < n; ++i){
        k *= 2;
    }
    m -= k;
    cout << m;
    return 0;
}