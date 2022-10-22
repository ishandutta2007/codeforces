#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,s1;
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll ans=0,tmp = a[n-1];
    ans+=a[n-1];
    for(int i=n-2;i>=0;i--){
            ll k=0;
        ans+=max(k,min(tmp-1,a[i]));

        tmp=max(k,min(tmp-1,a[i]));

    }
    cout << ans;

    return 0;

}