#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
//    <|_|>
 
const int MAX_VALEURS = (100 * 1000);
 
int Val[MAX_VALEURS];
 
char Entree[MAX_VALEURS];
 
int nbValeurs;
 
void Read() {
    scanf("%s", Entree);
    while (Entree[0] == 'I')
    {
        cout << "NO" << endl;
        scanf("%s", Entree);
        scanf("%s", Entree);
        scanf("%s", Entree);
    }
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