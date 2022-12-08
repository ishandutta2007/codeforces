#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pdd pair<double,double>
#define one 1
#define mp make_pair
#define ld long double
#define MOD 998244353 
#define MAXN 512345
#define RAIZ 800

int tab[RAIZ+10][RAIZ+10];
int val[MAXN];
int resp;
int32_t main(){

    int q;
    int t,x,y;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&t,&x,&y);
        if(t==1){
            for(int i=1;i<RAIZ;i++){
                tab[i][x%i]+=y;
            }
            val[x]+=y;
        }
        if(t==2){
            if(x<RAIZ)printf("%d\n",tab[x][y]);
            else{
                resp=0;
                for(int i=y;i<MAXN;i+=x)resp+=val[i];
                printf("%d\n",resp);
            }
        }
    }

    return 0;
}