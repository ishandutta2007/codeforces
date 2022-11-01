#include <cstdio>

using namespace std;

int n, m;
int ocj[105][105];
bool niz[105];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            char pom;
            scanf("%c", &pom);
            if (pom < '0' || pom > '9'){
               --j;
               continue;
            }
            ocj[i][j] = pom - '0';
        }
    }
    int rez = 0;
    for (int i = 0; i < m; ++i){
        int maks = 0;
        for (int j = 0; j < n; ++j){
            if (ocj[j][i] > maks){
               maks = ocj[j][i];
            }
        }
        for (int j = 0; j < n; ++j){
            if (ocj[j][i] == maks){
               if (niz[j]){
                  continue;
               }
               ++rez;
               niz[j] = true;
            }
        }
    }
    printf("%d\n", rez);
    //while (true);
    return 0;
}