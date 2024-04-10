// Hydro submission #621e056e691e5f399cb3806f@1646134638784
#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[50+10];
int main(){
    ans=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=a[k]&&a[i]>0){
            ans++;
        }
    }
    cout << ans;
    return 0;
}