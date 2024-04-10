#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
void solve(){
    int n;cin>>n;
    int arr[n];
    vector<int>loc,unloc;
    for(int i=0;i<n;i++)cin>>arr[i];
    bool a,locked[n+5];
    for(int i=0;i<n;i++){
        cin>>a;
        locked[i]=a;
        if(a)loc.pb(arr[i]);
        else unloc.pb(arr[i]);
    }
    int nowa=0,nowb=0;
    sort(unloc.begin(),unloc.end());
    reverse(unloc.begin(),unloc.end());
    for(int i=0;i<n;i++){
        if(locked[i]){
            cout<<loc[nowa]<<" ";
            nowa++;
        }
        else{
            cout<<unloc[nowb]<<" ";
            nowb++;
        }
    }
    cout<<endl;
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