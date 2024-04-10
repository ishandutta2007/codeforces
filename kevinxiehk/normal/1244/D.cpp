#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define int long long
using namespace std;
#define N 100010
ll cost[5][N];
int n;
ll corr[N];
ll corrv[N];
ll deg[N][10];
ll t,tt;
ll cnt=1;
ll now=1;
ll last=-1;
ll llast=-1;
int idk[25]{1,2,3,1,3,2,2,1,3,2,3,1,3,1,2,3,2,1,0,0,0,0,0,0,0};
ll mi=100000000000000000;
int minway;
main(){
    //freopen("123456789.txt","r",stdin);
    int n;
    cin>>n;
    
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            cin>>cost[i][j];
        }
    }
    for(int j=1;j<=n;j++)deg[j][0]=0;
    for(int i=1;i<n;i++){
        cin>>t>>tt;
        deg[t][0]++;
        deg[tt][0]++;
        deg[t][deg[t][0]]=tt;
        deg[tt][deg[tt][0]]=t;
        if(deg[t][0]>2||deg[tt][0]>2){cout<<"-1"<<endl;return 0;}
    }
    while(deg[now][0]!=1)now++;
    while(1){
        //cout<<now;
        corr[now]=cnt;
        corrv[cnt]=now;
        cnt++;
        llast=last;
        last=now;
        if(deg[now][0]==1&&llast!=-1)break;
        if(deg[now][1]==llast)now=deg[now][2];
        else now=deg[now][1];
    }
//cout<<"here"<<endl;
    for(int i=0;i<=5;i++){
        ll sum=0;
        for(int j=1;j<=n;j++){
            sum+=cost[idk[i*3+(j%3)]][corrv[j]];
        }
        if(sum<mi){mi=sum;minway=i;}
    }
    cout<<mi<<endl;
    for(int i=1;i<=n;i++){
        cout<<idk[minway*3+(corr[i]%3)];
        if(i==n)cout<<endl;
        else cout<<" ";
    }
    return 0;
}