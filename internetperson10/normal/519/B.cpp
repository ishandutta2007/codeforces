#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    long long int n, k, s=0, s2=0;
    cin >> n;
    for(int a=0; a<n; a++) {
        cin >> k;
        s+=k;
    }
    for(int a=1; a<n; a++) {
        cin >> k;
        s-=k;
        s2+=k;
    }
    cout << s << '\n';
    for(int a=2; a<n; a++) {
        cin >> k;
        s2-=k;
    }
    cout << s2 << '\n';
}