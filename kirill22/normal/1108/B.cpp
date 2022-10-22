#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,m,k,ans=0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if (n==2){
        cout << 1 << " " << 1;
        return 0;
    }
    cout << a[n-1];
    for(int i=n-2;i>-1;i--){
            if ( a[i]==a[i+1]){
                cout << " " << a[i];
                return 0;
            }
            else if (a[n-1]%a[i]!=0){
                cout << " " << a[i];
                return 0;
            }
    }

}