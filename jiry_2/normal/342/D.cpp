#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,pd[4][10100],x,y,gox[4]={1,0,-1,0},goy[4]={0,1,0,-1},w[16],dp[10100][8],mo=1000000007;
char getin(){
    char ch=getchar(); while (ch!='.'&&ch!='X'&&ch!='O') ch=getchar(); return ch;
}
int check(int k1,int k2,int k3){
    for (int i=0;i<3;i++){
        if (pd[i+1][k1]){
            if (k2&(1<<i)) return 0;
        }
        if (pd[i+1][k1-1]){
            if (k3&(1<<i)) return 0; else k3+=(1<<i);
        }
    }
    int a[3]={0};
    for (int i=0;i<3;i++) if ((k3&(1<<i))==0) a[i]--;
    for (int i=0;i<3;i++) if (k2&(1<<i)) a[i]++;
    for (int i=0;i<3;i++) if (a[i]<0) return 0;
    for (int i=0;i<2;i++) if (a[i]&&a[i+1]==0) return 0; else if (a[i]) a[i+1]=0;
    if (a[2]) return 0;
    //if (k1==1) cout<<k2<<" "<<k3<<endl;
    return 1;
}
int solve(int k){
    /*cout<<"solve "<<k<<" "<<w[k]<<endl;
    for (int i=1;i<=3;i++){
        for (int j=1;j<=n;j++)
            cout<<pd[i][j]<<" "; cout<<endl;} cout<<endl;*/
    memset(dp,0x00,sizeof dp);
    dp[0][7]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<8;j++)
            for (int k=0;k<8;k++)
                if (check(i,j,k)) dp[i][j]=(dp[i][j]+dp[i-1][k])%mo;
    int k1=0; for (int i=0;i<3;i++) if (pd[i+1][n]) k1+=(1<<i);// cout<<k1<<endl;
    /*for (int i=0;i<=7;i++){
        for (int j=1;j<=n;j++)
            cout<<dp[i][j]<<" "; cout<<endl;} cout<<endl;*/
    return dp[n][7^k1];
}
int dfs(int k1,int k2){
    if (k1==4) return w[k2]*solve(k2);
    int flag=0;
    for (int i=1;i<=2;i++){
        int k3=x+gox[k1]*i,k4=y+goy[k1]*i;
        if (k3<=0||k3>3||k4<=0||k4>n||pd[k3][k4]){flag=1; break;}
    }
    int ans=0;
    if (flag==0){
        for (int i=1;i<=2;i++){
            int k3=x+gox[k1]*i,k4=y+goy[k1]*i; pd[k3][k4]=1;
        }
        ans+=dfs(k1+1,k2+(1<<k1));
        for (int i=1;i<=2;i++){
            int k3=x+gox[k1]*i,k4=y+goy[k1]*i; pd[k3][k4]=0;
        }
    }
    ans=(ans+dfs(k1+1,k2))%mo; return ans;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=3;i++)
        for (int j=1;j<=n;j++){
            char ch=getin(); if (ch=='X') pd[i][j]=1; else if (ch=='O') {pd[i][j]=2; x=i; y=j;}
        }
    for (int i=1;i<16;i++){
        w[i]=1;
        for (int j=(i-1)&i;j;j=(j-1)&i)
            w[i]=w[i]-w[j];
    }
    cout<<(dfs(0,0)+mo)%mo<<endl; return 0;
}