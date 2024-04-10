#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int k,n[4],t[4],fin,start;

int i,j,x,y,z;

int TimeLeft[4][1005];
int Slobodna[4][1005],SC[4],pending[4];

long long tm;

int main(){
    scanf("%d%d%d%d%d%d%d",&k,n+1,n+2,n+3,t+1,t+2,t+3);
    //napuni prve masine
    pending[1] = k;
    fin = 0;
    for (i=1; i<=3; i++){
        for (j=1; j<=n[i]; j++){
            Slobodna[i][j] = j;
            TimeLeft[i][j] = 1000000000;
        }
        SC[i] = n[i];
    }
    while (fin < k){
        //nadji najskoriju masinu
        z = 1000000005;
        for (i=1; i<=3; i++){
            for (j=1; j<=n[i]; j++){
                if (TimeLeft[i][j] < z){
                    z = TimeLeft[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        //printf("> %d %d , %d %lld\n",x,y,z,tm);
        if (z < 1005){
            for (i=1; i<=3; i++){
                for (j=1; j<=n[i]; j++){
                    TimeLeft[i][j] -= z;
                    if (TimeLeft[i][j] == 0){
                        //masina je zavrsila
                        if (i==3){
                            fin++;
                        } else {
                            pending[i+1]++;
                        }
                        TimeLeft[i][j] = 1000000000;
                        Slobodna[i][++SC[i]] = j;
                    }
                }
            }
            tm+=z;
        }
        //upijanje poslova
        for (i=1; i<=3; i++){
            while (SC[i] > 0 && pending[i] > 0){
                //printf("upijam %d %d tm %lld postavlja %d\n",i,Slobodna[i][SC[i]],tm,t[i]);
                TimeLeft[i][Slobodna[i][SC[i]]] = t[i];
                SC[i]--;
                pending[i]--;
            }
        }
    }
    printf("%lld\n",tm);
    return 0;
}