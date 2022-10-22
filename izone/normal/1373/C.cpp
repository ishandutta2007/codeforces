#include<cstdio>
#include<algorithm>
using namespace std;
char p[1010000];
void Solve(){
    scanf("%s",p);
    int i, Mn = 0, s = 0;
    long long res=0;
    for(i=0;p[i];i++){
        if(p[i]=='-'){
            s--;
        }
        else{
            s++;
        }
        if(Mn>s){
            Mn=s;
            res+=i+1;
        }
    }
    res+=i;
    printf("%lld\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}