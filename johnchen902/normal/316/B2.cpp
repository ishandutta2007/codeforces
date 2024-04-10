#include <cstdio>
#include <cstdlib>

int n, x;
int a[1000];
int isNotEnd[1000]={};

int baever = 0;
int queues[1000]={};
int reachable[1000]={}, maxReach = 0;

int main(){
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i - 1);
        if(a[i - 1] != 0)
            isNotEnd[a[i - 1] - 1] = 1;
    }
    for(int i = 1; i <= n; i++)
        if(!isNotEnd[i - 1]){
            int j = i, len = 0, foundX = 0;
            while( j != 0 ){
                if(j == x){
                    foundX = 1;
                    len = 0;
                }
                j = a[j - 1];
                len++;
            }
            if( foundX )
                baever = len;
            else
                queues[len - 1]++;
        }
    maxReach = baever;
    reachable[baever - 1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = maxReach; j >= baever; j--){
            if( reachable[j - 1] ){
                for(int k = 1; k <= queues[i - 1]; k++){
                    reachable[j + i * k - 1] = 1;
                    if( maxReach < j + i * k)
                        maxReach = j + i * k;
                }
            }
        }
    }
    for(int j = baever; j <= maxReach; j++){
        if( reachable[j - 1] ){
            printf("%d\n", j);
        }
    }
    // system("pause");
    return 0;
}