#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void add(int a){cout<<"+ "<<a<<endl;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int triplet,straight,lastt,lasts,addt,adds;
    cin>>lastt>>lasts;
    int ans[n+5];
    for(int i=0;i<=n;i++)ans[i]=0;
    map<int,int>stadd;
    int t=0;
    for(int i=0;i<=n;i++){
        t+=i;
        stadd[t]=i;
    }
    bool uns[n+5];
    for(int i=0;i<=n;i++)uns[i]=false;
    int added[2][n+5];
    for(int i=n-1;i>=3;i--){
        add(i);
        cin>>triplet>>straight;
        addt=triplet-lastt;
        added[0][i]=addt;
        adds=straight-lasts;
        added[1][i]=adds;
        lastt=triplet;
        lasts=straight;
    }
    int oof[3]={1,2,1};
    for(int i=2;i>=0;i--){
        add(oof[i]);
        cin>>triplet>>straight;
        addt=triplet-lastt;
        added[0][i]=addt;
        adds=straight-lasts;
        added[1][i]=adds;
        lastt=triplet;
        lasts=straight;
    }
    ans[3]=added[1][0]-added[1][2]-1;
    ans[2]=added[1][2]/(ans[3]+1);
    ans[1]=stadd[added[0][0]];
    ans[4]=(added[1][1]-(ans[1]+1)*(ans[3]+1))/(ans[3]+1)-1;
    for(int i=3;i<=n-2;i++){
        ans[i+2]=(added[1][i]-(ans[i-1])*(ans[i+1]+1)-(ans[i-1])*(ans[i-2]))/(ans[i+1]+1)-1;
    }
    ans[n]++;
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<ans[i];
        if(i==n)cout<<endl;
        else cout<<" ";
    }
    return 0;
}