#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
#define double long double
using namespace std;
void solve(){
    int n,l;
    cin>>n>>l;
    int arr[n+5];
    arr[0]=0;arr[n+1]=l;
    for(int i=1;i<=n;i++)cin>>arr[i];
    double time[2][n+5];
    for(int i=0;i<=n;i++){
        time[0][i]=(double)(arr[i+1]-arr[i])/(double)(i+1);
        time[1][i]=(double)(arr[i+1]-arr[i])/(double)(n-i+1);
    }
    double answer=0,a=0,b=0;
    int ll=0,r=n+1;
    while(r-ll!=1){
        if(a+time[0][ll]<=b+time[1][r-1]){
            ll++;
            a+=time[0][ll-1];
        }
        else{
            r--;
            b+=time[1][r];
        }
        //cout<<ll<<" "<<r<<" "<<a<<" "<<b<<endl;
    }
    double ans=max(a,b);
    double dist=0;
    if(a>b){
        dist=(double)(a-b)*(n-r+2);
    }
    else{
        dist=(double)(b-a)*(ll+1);
    }
    //cout<<dist<<endl;
    //cout<<(arr[r]-arr[ll]-dist)<<" "<<n+2<<endl;
    ans+=(double)(arr[r]-arr[ll]-dist)/(double)(n+2);
    cout<<fixed<<setprecision(10)<<ans<<endl;
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