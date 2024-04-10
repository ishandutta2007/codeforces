#include <iostream>
#include <cstdio>
using namespace std;
 
//    <|_|>
 
const int MAX_VALEURS = 1000;
 
void Read() {
    char Val[1000];
    scanf("%s", Val);
    int nb = 0;
    if (Val[0] == ')')
    {
        printf("NO\n");
        return;
    }
    while (Val[nb] == '(' || Val[nb] == ')' || Val[nb] == '?')
    {
        nb ++;
    }
    if (Val[nb - 1] == '(')
    {
        printf("NO\n");
        return;
    }
    if (nb % 2 == 1)
    {
        printf("NO\n");
        return;
    }
    printf("YES\n");
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