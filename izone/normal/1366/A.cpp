#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, m;
void Solve(){
    int a, b;
    scanf("%d%d",&a,&b);
    if(a<b)swap(a,b);
    if(a>2*b)printf("%d\n",b);
    else printf("%d\n",(a+b)/3);
}
int main(){
      int TC;
      scanf("%d",&TC);
      while(TC--){
        Solve();
      }
}