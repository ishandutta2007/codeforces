#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
//  <|_|>
 
//  Why do we fall, sir ?

const int MAX_VALEURS = (200 * 1000);
 
int nbValeurs;

void Read() {
    scanf("%lld", &nbValeurs);
    printf("2 %lld\n", nbValeurs - 1);
    return;
}
 
signed main() {
    int nbTests = 1;
    scanf("%lld", &nbTests);
    while (nbTests --)
        Read();
    return 0;
}