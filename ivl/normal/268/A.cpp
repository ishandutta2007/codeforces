#include <cstdio>

using namespace std;

int n;
int color[100][2];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d%d", color[i], color[i] + 1);
    }
    int rez = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (i == j){
               continue;
            }
            if (color[i][0] == color[j][1]){
               ++rez;
            }
        }
    }
    printf("%d\n", rez);
    return 0;
}