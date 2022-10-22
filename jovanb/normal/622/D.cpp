#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a[1000005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<n; i+=2){
        a[(i+1)/2] = i;
        a[n-(i+1)/2+1] = i;
    }
    for(int i=2; i<n; i+=2){
        a[n + i/2] = i;
        a[n + n-i/2] = i;
    }
    for(int i=1; i<=2*n; i++){
        if(a[i]) cout << a[i] << " ";
        else cout << n << " ";
    }
    return 0;
}