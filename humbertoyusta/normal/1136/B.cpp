#include<bits/stdc++.h>
using namespace std;

int n,k,a[1010],b[1010],ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    cout << ( 2 * n + 1 + ( 2 * min(k-1,n-k) + max(k-1,n-k) ) );

    return 0;
}