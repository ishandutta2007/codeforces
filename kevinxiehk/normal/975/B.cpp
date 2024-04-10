#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n;
    n=14;
    int arr[n*3];
    for(int i=0;i<n;i++){cin>>arr[i];arr[i+n]=arr[i];}
    int arrt[n*3];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int i=0;i<n*3;i++)arrt[i]=arr[i];
        if(arrt[i]==0)continue;
        int aaa=arrt[i]%14;
        int bbb=arrt[i]/14;
        arrt[i]=0;
        for(int j=i+1;j<i+1+aaa;j++)arrt[j]++;
        for(int j=i;j<i+n;j++)arrt[j]+=bbb;
        int tmp=0;
        for(int j=i;j<i+n;j++)if(arrt[j]%2==0)tmp+=arrt[j];
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    //cin>>t;
    t=1;

    while(t--)solve();
    return 0;
}