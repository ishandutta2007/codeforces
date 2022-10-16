#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b,c;cin>>a>>b>>c;
    int sa=0,sb=0,sc=0;
    int arr[3][max(max(a,b),c)+5];
    for(int i=0;i<a;i++)cin>>arr[0][i],sa+=arr[0][i];
    for(int i=0;i<b;i++)cin>>arr[1][i],sb+=arr[1][i];
    for(int i=0;i<c;i++)cin>>arr[2][i],sc+=arr[2][i];
    sort(arr[0],arr[0]+a);
    sort(arr[1],arr[1]+b);
    sort(arr[2],arr[2]+c);
    cout<<sa+sb+sc-min(arr[0][0]+arr[1][0]+arr[2][0]-max(max(arr[0][0],arr[1][0]),arr[2][0]),min(min(sa,sb),sc))*2;
    cout<<"\n";
    return 0;
}