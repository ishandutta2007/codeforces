#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long dp[101000][3][3][3];
char ch[101000];
int n,m,x[101000];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",ch+1);
    for (int i=1;i<=n;i++) x[i]=ch[i]-'a'+1;
    for (int i=1;i<=m;i++){
        int k1=-1,k2=0,k3=0;
        if (i==x[1]) k2=0; else k2=-1; 
        if (i==x[2]) k3=0; else k3=-1;
        k2=max(k2,k1); k3=max(k2,k3);
        dp[1][k1+2][k2+2][k3+2]++;
    }
    for (int now=1;now<n;now++)
        for (int k1=0;k1<3;k1++)
            for (int k2=0;k2<3;k2++)
                for (int k3=0;k3<3;k3++)
                    if (dp[now][k1][k2][k3]){
                        long long k=dp[now][k1][k2][k3];
                    //  cout<<"fuck "<<now<<" "<<k1<<" "<<k2<<" "<<k3<<" "<<k<<endl;
                        for (int i=1;i<=m;i++){
                            int a=k2;
                            if (i==x[now]) a=max(a,k1+1);
                            int b=max(a,k3);
                            if (i==x[now+1]) b=max(b,k2+1);
                            int c=b;
                            if (i==x[now+2]) c=max(c,k3+1);
                            a=max(a-1,0); b=max(b-1,0); c=max(c-1,0);
                            if (a||b||c)dp[now+1][a][b][c]+=k;
                        }
                    }
    long long ans=0;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++){
            ans+=dp[n][i][1][j];
        }
    cout<<ans<<endl;
    return 0;
}