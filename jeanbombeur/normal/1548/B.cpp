#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
//  <|_|>
 
//  Why do we fall, sir ?
 
const int TAILLE_ARBRE = (1 << 18);
const int MAX_VALEURS = (1000 * 1000);
 
int Tree[2 * TAILLE_ARBRE];
 
int nbValeurs;
 
int Gcd(int a, int b) {
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}
 
int GetGcd(int gauche, int droite) {
    int ans = Tree[gauche + nbValeurs];
    for (gauche += nbValeurs, droite += nbValeurs; gauche < droite; gauche >>= 1, droite >>= 1)
    {
        if (gauche & 1)
            ans = Gcd(ans, Tree[gauche ++]);
        if (droite & 1)
            ans = Gcd(ans, Tree[-- droite]);
    }
    return ans;
}
 
void Read() {
    int last;
    scanf("%lld %lld", &nbValeurs, &last);
    nbValeurs --;
    for (int i = 0; i < nbValeurs; i ++)
    {
        int a;
        scanf("%lld", &a);
        Tree[nbValeurs + i] = abs(a - last);
        last = a;
    }
    for (int i = nbValeurs - 1; i > 0; i --)
    {
        Tree[i] = Gcd(Tree[2 * i], Tree[2 * i + 1]);
    }
    
    int maxi = 1;
    int curGcd = Tree[nbValeurs];
    
    int droite = 1;
    
    for (int i = 0; i < nbValeurs; i ++)
    {
        while (curGcd > 1 && droite < nbValeurs)
        {
            curGcd = Gcd(curGcd, Tree[nbValeurs + droite]);
            droite ++;
        }
        maxi = max(maxi, droite - i + (curGcd > 1));
        droite = max(droite, i + 2);
        curGcd = GetGcd(i + 1, droite);
    }
    
    printf("%lld\n", maxi);
    
    return;
}
 
signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Read();
    return 0;
}