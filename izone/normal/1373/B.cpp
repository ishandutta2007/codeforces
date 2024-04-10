#include<cstdio>
#include<algorithm>
using namespace std;
char p[1010];
void Solve(){
    scanf("%s",p);
    int i;
    int C[2]={0};
    for(i=0;p[i];i++){
        C[p[i]-'0']++;
    }
    if(min(C[0],C[1])%2){
        puts("DA");
    }
    else{
        puts("NET");
    }
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}