#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    int freq[105];
    for(int i=0;i<=101;i++)freq[i]=0;
    for(int i=0;i<n;i++)freq[arr[i]]++;
    int ans=0;
    bool a=false;
    for(int i=0;i<=101;i++){
        if(freq[i]>=2)continue;
        else if(freq[i]==1){
            if(a==false){
                ans+=i;
                a=true;
            }
        }
        else{
            ans+=i;
            if(a==false)ans+=i;
            cout<<ans<<endl;
            return;
        }
    }
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 
    cin>>t;
    
    while(t--)solve();
    return 0;
}