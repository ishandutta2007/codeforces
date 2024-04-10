#include <cstdio>

using namespace std;

int n, m;
char in[1005][1005];

bool bb[1005];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", in[i]);
    int r = 0;
    for (int i = 0; i < m; ++i){
        bool ch = false;
        for (int j = 1; j < n; ++j){
            if (bb[j]) continue;
            if (in[j][i] < in[j - 1][i]) ch = true;
        }
        if (ch){++r; continue;}
        for (int j = 1; j < n; ++j){
            if (bb[j]) continue;
            if (in[j][i] != in[j - 1][i]) bb[j] = true;
        }
    }
    printf("%d\n", r);
    return 0;
}