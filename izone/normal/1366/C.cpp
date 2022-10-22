#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
int C[100][2];
void Solve(){
    int i, j;
    scanf("%d%d",&n,&m);
    for(i=0;i<100;i++)C[i][0]=C[i][1]=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int a;
            scanf("%d",&a);
            if(i+j==n-i-1+m-j-1)continue;
            C[min(i+j,n-i-1+m-j-1)][a]++;
        }
    }
    int s=0;
    for(i=0;i<100;i++)s+=min(C[i][0],C[i][1]);
    printf("%d\n",s);
}
int main(){
      int TC;
      scanf("%d",&TC);
      while(TC--){
        Solve();
      }
}