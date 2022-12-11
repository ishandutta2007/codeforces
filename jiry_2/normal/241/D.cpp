#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int x[40],n,m,p,y[40],dp[33][32][50000],flag;
vector<int>S;
void print(int k1,int k2,int k3){
    if (dp[k1][k2][k3]==0) return;
    if (k2==0&&k3==0){
        cout<<"Yes"<<endl; cout<<S.size()<<endl;
        for (int i=0;i<S.size();i++) cout<<S[i]<<" "; cout<<endl; flag=1; return;
    }
    if (k1==n) return;
    if (dp[k1+1][k2][k3]) print(k1+1,k2,k3); int k4=0; if (flag) return;
    if (x[k1+1]>=10) k4=(k3*100+x[k1+1])%p; else k4=(k3*10+x[k1+1])%p;
    if (dp[k1+1][k2^x[k1+1]][k4]){
        S.push_back(y[k1+1]); print(k1+1,k2^x[k1+1],k4); S.pop_back();
    }
    dp[k1][k2][k3]=0; return;
}
int main(){
    scanf("%d%d",&m,&p); for (int i=1;i<=m;i++){int k1; scanf("%d",&k1); if (k1>=32) continue; x[++n]=k1; y[n]=i;}
    for (int i=1;i<=n;i++) dp[i][x[i]][x[i]%p]=1;
    for (int i=2;i<=n;i++)
        for (int j=0;j<32;j++)
            for (int k=0;k<p;k++){
                if (dp[i-1][j][k]==0) continue;
                dp[i][j][k]=1; int k1=0;
                if (x[i]>=10) k1=(k*100+x[i])%p; else k1=(k*10+x[i])%p;
                dp[i][j^x[i]][k1]=1;
            }
    flag=0; 
    for (int i=1;i<=n;i++){
        S.push_back(y[i]); print(i,x[i],x[i]%p); if (flag) return 0;
    }
    cout<<"No"<<endl; return 0;
}