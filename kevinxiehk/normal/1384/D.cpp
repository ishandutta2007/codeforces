#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    int bitcnt[40];
    for(int i=0;i<40;i++)bitcnt[i]=0;
    for(int i=0;i<n;i++){
        int t=arr[i];
        for(int j=0;j<=39;j++){
            bitcnt[j]+=t%2;
            t/=2;
        }
    }
    int t=39;
    //for(int i=0;i<15;i++)cout<<bitcnt[i]<<" ";
    while(t>=0&&bitcnt[t]%2==0)t--;
    if(t==-1){cout<<"DRAW"<<endl;return;}
    int aaa=bitcnt[t];
    int bbb=n-aaa;  
    if(aaa==1){cout<<"WIN"<<endl;return;}
    cout<<( aaa % 4 == 1 ? "WIN" : bbb%2 ? "WIN" : "LOSE" ) << endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}