#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int in[105][3];
int r;

int main(){
    scanf("%d%d", &n, &k);
    //k = n / k;
    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        ++in[i % k][x];
    }
    for (int i = 0; i < k; ++i) r += min(in[i][1], in[i][2]);
    printf("%d\n", r);
    return 0;
}