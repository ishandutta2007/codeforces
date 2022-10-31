// Hydro submission #618e10ca609bbc8c787346a7@1636700362965
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=205;
int _,n,a[N],f[N][N<<1];
int main() {
    scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(f,10,sizeof(f));
        for(int i=0;i<=2*n;i++)f[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2*n;j++){
                f[i][j]=f[i-1][j-1]+abs(j-a[i]);
            }
            for(int j=1;j<=2*n;j++)f[i][j]=min(f[i][j],f[i][j-1]);
//            for(int j=1;j<=2*n;j++)cout<<f[i][j]<<' ';
//            cout<<endl;
        }
        printf("%d\n",f[n][2*n]);
    }
    return 0;
}