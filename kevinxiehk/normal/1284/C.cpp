#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[n+5];
    arr[1]=1;
    for(int i=2;i<=n;i++)arr[i]=(i*arr[i-1])%m;
    int ans=0,a;
    for(int i=1;i<=n;i++){
        a=n-i+1;
        a*=arr[a];
        a%=m;
        a*=arr[i];
        a%=m;
        ans+=a;
        ans%=m;
    }
    cout<<ans%m<<endl;
    return 0;
}