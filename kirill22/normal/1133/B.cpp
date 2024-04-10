#include <bits/stdc++.h>3c
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(k,0);
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        a[t%k]++;
    }
    int ans=0;
    for(int i=0;i<=k/2;i++){
        if (i!=0 && i!=(k-i)%k){
            ans+=min(a[i],a[k-i])*2;
        }
        else{
            ans+=(a[i]/2)*2;
        }
       //cout << ans << "  ";
    }
    cout << ans;

}