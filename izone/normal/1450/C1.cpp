#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, C[3];
char p[310][310];
void Solve(){
    int i, j;
    scanf("%d",&n);
    C[0]=C[1]=C[2]=0;
    for(i=0;i<n;i++){
        scanf("%s",p[i]);
        for(j=0;j<n;j++){
            if(p[i][j]=='X'){
                C[(i+j)%3]++;
            }
        }
    }
    int pv=-1,Mn=1e9;
    for(i=0;i<3;i++)if(Mn>C[i])Mn=C[i],pv=i;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(p[i][j]=='X' && (i+j)%3 == pv)p[i][j]='O';
        }
        printf("%s\n",p[i]);
    }
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}