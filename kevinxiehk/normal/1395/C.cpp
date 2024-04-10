#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n+5];
    int b[m+5];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    bool can[n+5][m+5];
    int cancnt[n+5];
    for(int i=0;i<n;i++)cancnt[i]=m;
    stack<int>ahh[n+5];
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)can[i][j]=true;
    int ans=0;
    for(int now=pow(2,9);now>=1;now/=2){
        bool okk=true,ok=true;
        for(int i=0;i<n;i++){
            if((now&a[i])==0)ok=true;
            else{
                ok=false;
                for(int j=0;j<m;j++){
                    if(can[i][j]){
                        if((b[j]&now)>0)ahh[i].push(j);
                        else ok=true;
                    }
                }
            }
            if(!ok)okk=false;
        }
        if(!okk){
            ans+=now;
            for(int i=0;i<n;i++){while(!ahh[i].empty()){ahh[i].pop();}}
        }
        else{
            for(int i=0;i<n;i++){
                cancnt[i]-=ahh[i].size();
                while(!ahh[i].empty()){
                    can[i][ahh[i].top()]=false;
                    ahh[i].pop();
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}