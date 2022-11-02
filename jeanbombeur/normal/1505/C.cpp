#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
 
//    <|_|>
 
const int MAX_VALEURS = (100 * 1000);
 
int Val[MAX_VALEURS];
 
char Entree[MAX_VALEURS];
 
int nbValeurs;
 
void Read() {
    scanf("%s", Entree);
    int sz = strlen(Entree);
    for (int i = 2; i < sz; i ++)
    {
        int a = Entree[i] - 'A';
        int b = Entree[i - 1] - 'A';
        int c = Entree[i - 2] - 'A';
        if (a != ((b + c) % 26))
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    return;
}
 
signed main() {
    int nbTests = 1;
    //scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}