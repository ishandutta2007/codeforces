#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
void solve(){
    int n,m;
    cin>>n;
    int arr1[n+5];
    for(int i=0;i<n;i++)cin>>arr1[i];
    cin>>m;
    pair<int,int>arr2[m+5];
    for(int i=0;i<m;i++)cin>>arr2[i].fi>>arr2[i].se;
    int need[n+5];
    for(int i=0;i<=n;i++)need[i]=0;
    for(int i=0;i<m;i++)need[arr2[i].se]=max(need[arr2[i].se],arr2[i].fi);
    for(int i=n-1;i>=0;i--)need[i]=max(need[i],need[i+1]);
    int now=0;
    int oof=0;
    int cnt=0;
    while(now<n){
        oof=0;
        int thismax=arr1[now];
        while(thismax<=need[oof+1]&&(now+oof)<n){
            oof++;
            thismax=max(thismax,arr1[now+oof]);
        }
        //oof--;
        if(oof<=0){cout<<"-1"<<endl;return;}
        cnt++;
        now+=oof;
        //cout<<"     "<<now<<endl;
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