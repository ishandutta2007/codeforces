#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m,k,ans=0;
    cin >> n ;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    for(int i=0;i<n/2;i++){
            ll b=a[i],c=a[n-i-1];
            ans+=(b+c)*(b+c);
    }
    cout << ans;







}