#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, LP[10100000], M =10000000;
int R[501000][2];
int main(){
    int i, j;
    for(i=2;i<=M;i++){
        if(LP[i])continue;
        for(j=i;j<=M;j+=i){
            LP[j]=i;
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        int u = LP[a], tp=a, zz=1;
        while(tp%u==0)tp/=u,zz*=u;
        if(tp==1){
            R[i][0]=R[i][1]=-1;
        }
        else R[i][0]=zz,R[i][1]=tp;
    }
    for(i=1;i<=n;i++)printf("%d ",R[i][0]);
    puts("");
    for(i=1;i<=n;i++)printf("%d ",R[i][1]);
    puts("");
}