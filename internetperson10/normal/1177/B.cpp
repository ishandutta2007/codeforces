#include <bits/stdc++.h>

using namespace std;

long long int pow10(int n) {
    long long int r=1;
    while(n--) r*=10;
    return r;
}

int main() {
    long long int n, curr=9, dig=1;
    cin >> n;
    while(n>curr*dig) {
        n-=(curr*dig);
        curr*=10;
        dig++;
    }
    n--;
    int pos=n%dig;
    n/=dig;
    dig--;
    n+=pow10(dig);
    n/=pow10(dig-pos);
    cout << n%10 << '\n';
}