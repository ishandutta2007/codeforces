#include <cstdio>

using namespace std;

int n;
int in[105][2];

int main(){
    scanf("%d", &n);
    int lo = 0, hi = 0;
    bool check = false;
    for (int i = 0; i < n; ++i){
        scanf("%d%d", in[i], in[i] + 1);
        lo = (lo + in[i][0]) & 1;
        hi = (hi + in[i][1]) & 1;
        if (in[i][0] % 2 != in[i][1] % 2) check = true;
    }
    if (lo == 0 && hi == 0){printf("0\n"); return 0;}
    if (lo == 1 && hi == 1 && check){printf("1\n"); return 0;}
    printf("-1\n");
    return 0;
}