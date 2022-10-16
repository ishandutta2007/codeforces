#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n,m,kk,k,z;
    cin>>n>>k>>z;
    int arr[n+5];
    for(int i=1;i<=n;i++)cin>>arr[i];
    int sum=0;
    for(int i=1;i<=k+1;i++)sum+=arr[i];
    int t,tt;
    int idk=0;
    for(int i=1;i<=k+1;i++){
        t=0,tt=0;
        int ehh=z,now=k+1;
        while(ehh>0&&now>=i+3){
            tt+=arr[i]+arr[i+1];
            tt-=(arr[now]+arr[now-1]);
            now-=2;
            ehh--;
            t=max(t,tt);
            if(ehh){
                int a=-1;
                if(now!=i+1&&now>=3){
                    a=arr[now-2]-arr[now];
                }
                t=max(t,tt+a);
            }
        }
        if(ehh){
            int a=-1;
            if(now!=i+1&&now>=3){
                a=arr[now-2]-arr[now];
            }
            t=max(t,tt+a);
        }
        idk=max(idk,t);
    }
    cout<<sum+idk<<endl;
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