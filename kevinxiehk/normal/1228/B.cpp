#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n+5][m+5];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)arr[i][j]=0;
    int t;
    bool nah=false;
    for(int i=0;i<n;i++){
        cin>>t;
        for(int j=0;j<t;j++){if(arr[i][j]==-1)nah=1;arr[i][j]=1;}
        if(arr[i][t]==1)nah=1;
        arr[i][t]=-1;
    }
    for(int i=0;i<m;i++){
        cin>>t;
        for(int j=0;j<t;j++){if(arr[j][i]==-1)nah=1;arr[j][i]=1;}
        if(arr[t][i]==1)nah=1;
        arr[t][i]=-1;
    }
    if(nah){cout<<"0"<<endl;return 0;}
    long long cnt=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(arr[i][j]==false)cnt++;
    int ans=1;
    while(cnt){
        ans*=2;
        ans%=MOD;
        cnt--;
    }
    cout<<ans<<endl;
    return 0;
}