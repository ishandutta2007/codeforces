#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

struct env{int w, h, n;}a[5005];
bool cmp(env a, env b){
    return pi(a.w,a.h) < pi(b.w,b.h);
}

int n,w,h;
int dp[5005], tra[5005];

int main(){
    scanf("%d %d %d",&n,&w,&h);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].w,&a[i].h);
        a[i].n = i;
    }
    sort(a,a+n,cmp);
    for (int i=n-1; i>=0; i--) {
        for (int j=i+1; j<n; j++) {
            if(a[j].w > a[i].w && a[j].h > a[i].h){
                if(dp[j] > dp[i]){
                    dp[i] = dp[j];
                    tra[i] = j;
                }
            }
        }
        dp[i]++;
    }
    int opt = 0, t = -1;
    for (int i=0; i<n; i++) {
        if(a[i].w > w && a[i].h > h){
            if(opt < dp[i]){
                opt = dp[i];
                t = i;
            }
        }
    }
    if(t == -1){
        puts("0");
        return 0;
    }
    printf("%d\n",opt);
    while (opt) {
        printf("%d ",a[t].n + 1);
        opt--;
        t = tra[t];
    }
}