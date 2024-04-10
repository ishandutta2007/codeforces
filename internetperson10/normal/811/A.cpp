#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, a, l=0, r=31700, mid;
    cin >> k >> a;
    k = 2*floor(sqrt(k));
    while(l+1!=r) {
        mid = (l+r)/2;
        if(mid*mid + mid > a) r = mid;
        else l = mid;
    }
    a = 2*l+1;
    cout << (k < a ? "Vladik" : "Valera");
}