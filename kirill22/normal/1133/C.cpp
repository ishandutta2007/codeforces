#include <bits/stdc++.h>3c
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ii=0,tmp=0,ans=0;
    for(int i=0;i<n;i++){
        if (ii<n-1){
            while(ii<n-1 && a[i]+5>=a[ii+1]){
                ii++;
            }
        }
        ans=max(ans,ii-i+1);
    }
    cout << ans;
}