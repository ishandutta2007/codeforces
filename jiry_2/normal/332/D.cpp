#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int w[2001][2001],n,k,num[2001];
long double C[2001][2001];
int main(){
    scanf("%d%d",&n,&k); 
    for (int i=1;i<=n;i++) 
        for (int j=i+1;j<=n;j++){
            scanf("%d",&w[i][j]); if (w[i][j]!=-1){num[i]++; num[j]++;} w[j][i]=w[i][j];
        }
    for (int i=0;i<=n;i++){
        C[i][0]=1; for (int j=1;j<=i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    long double tot=0,ans=0;
    for (int i=1;i<=n;i++)
        if (num[i]>=k){
            tot+=C[num[i]][k];
            for (int j=1;j<=n;j++)
                if (i!=j&&w[i][j]!=-1) ans+=C[num[i]-1][k-1]*w[i][j];
        }
    //cout<<(double)tot<<" "<<(double)ans<<endl;
    //for (int i=1;i<=n;i++) cout<<num[i]<<" "; cout<<endl;
    cout<<(long long)trunc(ans/tot+1e-11)<<endl; return 0;
}