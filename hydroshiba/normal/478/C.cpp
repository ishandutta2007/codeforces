#include "bits/stdc++.h"
using namespace std;

long long a, b, c;

long long solve(long long a, long long b, long long c){
    if(c > 2 * (b + a)) return b + a;
    return (a + b + c) / 3;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);

    cout << solve(a, b, c);
}