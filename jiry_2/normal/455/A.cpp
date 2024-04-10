#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,x[100010],a[100010],b[100010];
long long f[100010][2];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    memset(b,0x00,sizeof b); int len=1;
    sort(x+1,x+n+1); a[1]=x[1]; b[1]=1; 
    for (int i=2;i<=n;i++){
        if (x[i]!=x[i-1]){len++; a[len]=x[i];} b[len]++;
    }
    memset(f,0x00,sizeof f); a[0]=-1000;
    for (int i=1;i<=len;i++){
        if (a[i-1]==a[i]-1){
            f[i][0]=max(f[i-1][0],f[i-1][1]);
            f[i][1]=f[i-1][0]+1ll*a[i]*b[i];
        } else{
            f[i][0]=max(f[i-1][0],f[i-1][1]);
            f[i][1]=max(f[i-1][0],f[i-1][1])+1ll*a[i]*b[i];
        }
    }
    cout<<max(f[len][0],f[len][1])<<endl; return 0;
}