#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    int n;
    cin>>n;
    int arr[n+5],ind[n+5],cnt[n+5];
    for(int i=0;i<=n;i++)ind[i]=-1;
    int c=0,now=1,id=1;
    for(int i=1;i<=n;i++)cin>>arr[i];
    while(c<n){
        now=1;
        int tc=0;
        while(ind[now]!=-1)now++;
        int begin=now;
        do{
           // cout<<now<<" ";
            c++;
            tc++;
            ind[now]=id;
            now=arr[now];
        }while(now!=begin);
        cnt[id]=tc;
        id++;
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[ind[i]];
        if(i==n)cout<<endl;
        else cout<<" ";
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}