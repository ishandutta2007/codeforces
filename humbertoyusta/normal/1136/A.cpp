#include<bits/stdc++.h>
using namespace std;

int n,k,a[1010],b[1010],ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ans = n;

    for(int i=1; i<=n; i++)
        cin >> a[i] >> b[i];

    cin >> k;

    for(int i=1; i<=n; i++)
        if(b[i] < k) ans--;

    cout << ans;

    return 0;
}