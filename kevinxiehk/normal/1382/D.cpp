#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n;
    cin>>n;
    bool used[n*2+5];
    int arr[n*2+5];
    for(int i=0;i<n*2;i++)cin>>arr[i];
    for(int i=0;i<=2*n;i++){
        used[i]=false;
    }
    vector<int>len;
    int ed=2*n-1;
    int topp=n*2;
    for(int i=2*n-1;i>=0;i--){
        used[arr[i]]=true;
        //cout<<arr[i]<<endl;
        if(arr[i]==topp){
            //cout<<"q"<<endl;
            len.pb(ed-i+1);
            ed=i-1;
            while(used[topp])topp--;
        }
    }
    int aaa=len.size();
    int knp[aaa+5][n+5];
    for(int i=0;i<=n;i++)knp[0][i]=0;
    for(int i=1;i<=aaa;i++){
        for(int j=0;j<=n;j++){
            if(j>=len[i-1]){
                knp[i][j]=max(knp[i-1][j-len[i-1]]+len[i-1],knp[i-1][j]);
            }
            else knp[i][j]=knp[i-1][j];
        }
    }
    //cout<<knp[aaa][n]<<" "<<aaa<<endl;
    if(knp[aaa][n]==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}