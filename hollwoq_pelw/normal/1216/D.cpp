#include<bits/stdc++.h>
using namespace std;

int main(){
    long long r = 0; // total lost swords +\+ :f
    int n,m=0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > m) m = a[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != m){
            //cout << k << endl;
            r+=m-a[i];
            if (k == 0) k = m-a[i];
            else k = __gcd(k,m-a[i]);
        }
    }
    cout << r/k << ' ' << k;
    return 0;
}