#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
bool cmp(int a,int b){return a>b;}
void solve(){
    int n;
    cin>>n;
    int sum=0;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i],sum+=arr[i];
    sort(arr,arr+n,cmp);
    if(arr[0]*2>sum||sum%2)cout<<"T"<<endl;
    else cout<<"HL"<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;

    cin>>t;
    
    while(t--)solve();
    return 0;
}