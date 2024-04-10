#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    long long n,r;
    cin>>n>>r;
    long long arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    arr[n]=-1;
    sort(arr,arr+n);
    long long cnt=0;
    long long d=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]<=d||arr[i]==arr[i+1])continue;
        cnt++;
        d+=r;
    }
    cout<<cnt<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}