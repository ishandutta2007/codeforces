#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char p[1010];
void Solve(){
    scanf("%d",&n);
    scanf("%s",p);
    sort(p,p+n);
    printf("%s\n",p);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}