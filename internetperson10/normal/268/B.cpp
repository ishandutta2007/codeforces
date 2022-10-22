#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int s=n;
    for(int a=1; a<n; a++) {
        s+=(a)*(n-a);
    }
    cout << s;
}