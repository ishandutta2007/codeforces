#include <cstdio>

using namespace std;

int n, m;
char niz[105][105];
bool ex[105][30];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%s", niz[i]);
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            ex[j][niz[i][j] - 'A'] = true;
        }
    }
    long long rez = 1, pom = 0;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < 30; ++j){
            if (ex[i][j]){
               ++pom;
            }
        }
        rez *= pom;
        if (rez > 1000000007){
           rez = rez % 1000000007;
        }
        pom = 0;
    }
    printf("%I64d\n", rez);
    return 0;
}