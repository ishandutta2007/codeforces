#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
int p[50];
void solve(){
    int ans=0;
    int n;
    cin>>n;
    int nn=n;
    if(n==1){cout<<1<<endl;return;}
    int arr[50];
    for(int i=0;i<=45;i++)arr[i]=0;
    for(int i=39;i>=0;i--){
        while(n>=p[i]){
            n-=p[i];
            arr[i]++;
        }
        //cout<<arr[i]<<endl;
    }
    int t=40;
    int lol=-1;
    for(int i=0;i<=39;i++)if(arr[i]==2)lol=i;
    //cout<<lol<<endl;
    if(lol==-1){cout<<nn<<endl;return;}
    t=lol;
    while(arr[t]!=0)t++;
    arr[t]++;
    for(int i=40;i>=t;i--){
        ans+=p[i]*arr[i];
    }
    cout<<ans<<endl;
}
main(){
    p[0]=1;
    for(int i=1;i<=39;i++){
        p[i]=p[i-1]*3;
    }
    int q;
    cin>>q;
    while(q--)solve();
    return 0;
}