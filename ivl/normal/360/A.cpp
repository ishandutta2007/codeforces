#include <cstdio>
#include <utility>
#define x first
#define y second
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int in[5005][4];

int dev[5005];
int limit[5005];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){scanf("%d%d%d%d", in[i], in[i] + 1, in[i] + 2, in[i] + 3); --in[i][1]; --in[i][2];}
    for (int i = 0; i < n; ++i) limit[i] = 1000000000;
    for (int i = 0; i < m; ++i){
        //for (int j = 0; j < n; ++j) printf("%d ", limit[j]);
        //printf("\n");
        if (in[i][0] == 1){
           for (int j = in[i][1]; j <= in[i][2]; ++j){
               dev[j] += in[i][3];
           }
        }
        else {
             for (int j = in[i][1]; j <= in[i][2]; ++j){
                 limit[j] = min(limit[j], in[i][3] - dev[j]);
             }
        }
    }
    for (int i = 0; i < n; ++i) dev[i] = 0;
    for (int i = 0; i < m; ++i){
        if (in[i][0] == 1){
           for (int j = in[i][1]; j <= in[i][2]; ++j) dev[j] += in[i][3];
           continue;
        }
        int pos = -1;
        for (int j = in[i][1]; j <= in[i][2]; ++j){
            if (limit[j] + dev[j] == in[i][3]){
               pos = j;
               break;
            }
        }
        if (pos == -1){printf("NO\n"); return 0;}
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i){
        printf("%d ", limit[i]);
    }
    return 0;
}