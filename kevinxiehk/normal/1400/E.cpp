#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
int n;
int arr[5005];
int dfs(int l,int r,int k){
    if(l==r){
        if(arr[l]==k)return 0;
        else return 1;
    }
    int m=min_element(arr+l,arr+r+1)-arr;
    int tans=arr[m]-k;
    if(m<r)tans+=dfs(m+1,r,arr[m]);
    if(m>l)tans+=dfs(l,m-1,arr[m]);
    //cout<<l<<" "<<r<<" "<<tans<<" "<<k<<" "<<m<<endl;
    return min(r-l+1,tans); 
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<dfs(0,n-1,0)<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;

    //cin>>t;
    
    while(t--)solve();
    return 0;
}