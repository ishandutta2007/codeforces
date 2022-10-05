#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    if(n < 3){
        puts("-1"); return 0;
    }
    if(n % 2) cout << (n * n - 1) / 2 << ' ' << (n * n + 1) / 2;
    else cout << (n * n / 4) - 1 << ' ' << (n * n / 4) + 1;
}