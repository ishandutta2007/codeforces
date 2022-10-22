#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, k, s=1;
    cin >> n >> k;
    while(k%2==0) {
        s++;
        k/=2;
    }
    cout << s;
}