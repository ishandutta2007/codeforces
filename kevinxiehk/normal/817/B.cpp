#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int anc=arr[2];
    int behcnt=0;
    int infcnt=0;
    for(int i=2;i<n;i++)if(arr[i]==anc)behcnt++;
    for(int i=2;i>=0;i--)if(arr[i]==anc)infcnt++;
    behcnt+=infcnt;
    int wtf=infcnt;
    int ans=1;
    for(infcnt;infcnt>0;infcnt--){ans*=(behcnt-infcnt);}
    for(wtf;wtf>=1;wtf--)ans/=wtf;
    cout<<ans<<endl;
    return 0;
}