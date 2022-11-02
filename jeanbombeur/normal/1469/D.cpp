#include <iostream>
#include <cstdio>
using namespace std;
 
//    <|_|>
 
const int MAX_VALEURS = (200 * 1000);

pair <int, int> Operations[MAX_VALEURS + 5];
int nbOperations;

int nbValeurs;

void Read() {
    scanf("%d", &nbValeurs);
    nbOperations = 0;
    int cur = nbValeurs;
    for (int i = nbValeurs - 1; i > 2; i --)
    {
        if ((cur + i - 1) / i >= i)
        {
            Operations[nbOperations ++] = {nbValeurs, i};
            cur = (cur + i - 1) / i;
        }
        Operations[nbOperations ++] = {i, nbValeurs};
    }
    while (cur >= 2)
    {
        Operations[nbOperations ++] = {nbValeurs, 2};
        cur = (cur + 1) / 2;
    }
    printf("%d\n", nbOperations);
    for (int i = 0; i < nbOperations; i ++)
    {
        printf("%d %d\n", Operations[i].first, Operations[i].second);
    }
    return;
}
 
int main() {
    int nbTests;
    scanf("%d", &nbTests);
    for (int i = 0; i < nbTests; i ++)
    {
        Read();
    }
    return 0;
}