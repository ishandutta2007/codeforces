#include <bits/stdc++.h>
using namespace std;

long long n, m, k,ans;
int main(){
    cin >> n >> m >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    ans = (m/(k+1))*(k*a[n-1]+a[n-2])+(m%(k+1))*a[n-1];
    cout << ans;
    return 0;
}