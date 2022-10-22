#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, m;
void Solve(){
    int i;
    scanf("%d%d%d",&n,&K,&m);
    int b=K,e=K;
    for(i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        if(max(b,l)<=min(e,r)){
            b=min(l,b);
            e=max(r,e);
        }
    }
    printf("%d\n",e-b+1);
}
int main(){
      int TC;
      scanf("%d",&TC);
      while(TC--){
        Solve();
      }
}