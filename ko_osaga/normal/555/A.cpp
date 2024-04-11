#include <cstdio>
#include <vector>
using namespace std;

int n, k;
int lab[100005];
int low[100005];
int tmp[100005];

int main(){
    scanf("%d %d",&n,&k);
    int cnt = 0;
    for (int i=0; i<k; i++) {
        int t;
        scanf("%d",&t);
        for (int j=0; j<t; j++) {
            scanf("%d",&tmp[j]);
        }
        cnt += (t - 1);
        for (int j=1; j<t; j++) {
            if(tmp[0] ==1 && tmp[j] == tmp[j-1] + 1) cnt-=2;
            else break;
        }
        for(int j=0; j<t; j++){
            lab[tmp[j]]= i;
        }
    }
    cnt += n-1;
    printf("%d",cnt);
}