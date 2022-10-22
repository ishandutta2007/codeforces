#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;
    cin >> n;
    cout << (n%2 ? (n+1)/2*-1 : (n+1)/2);
}