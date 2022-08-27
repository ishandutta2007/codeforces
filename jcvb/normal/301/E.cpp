#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
#define mo 1000000007
int n,m,k;
int C[105][105];
int f[2][105][105][105]={0};
inline void upd(int &a,int b){
    a+=b;if(a>=mo)a-=mo;
}
int main()
{   scanf("%d%d%d",&n,&m,&k);
    C[0][0]=1;
    for (int i=1;i<=100;i++){
        C[i][0]=1;
        for (int j=1;j<=100;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            if(C[i][j]>1000)C[i][j]=1000;
        }
    }
    int ans=0;
    for (int i=1;i<=m;i++){
        for (int c=1;c<=n;c++)
            upd(f[i&1][c][c][1],1);
        memset(f[i+1&1],0,sizeof(f[i+1&1]));
        for (int c=1;c<=n;c++)
            for (int p=1;p<=k;p++){
                upd(ans,f[i&1][0][c][p]);   
                if(i==m)continue;           
                for (int x=1,v;x<=n;x++)
                    if(v=f[i&1][x][c][p]){
                        for (int t=x;c+t<=n;t++){
                            int np=p*C[t-1][x-1];
                            if(np>k)break;
                            upd(f[i+1&1][t-x][c+t][np],v);
                        }
                    }
            }
    }
    printf("%d\n",ans);
    return 0;
}