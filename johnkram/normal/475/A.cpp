#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int a[]={28,56,83,110,30,58,112,32,60,114,34,62,116,36,64,118,38,66,120,40,68,122,42,70,124,44,72,126,46,74,128,48,76,130};
int n,i;
char c[]="+------------------------+\n|#.#.#.#.#.#.#.#.#.#.#.|D|)\n|#.#.#.#.#.#.#.#.#.#.#.|.|\n|#.......................|\n|#.#.#.#.#.#.#.#.#.#.#.|.|)\n+------------------------+";
int main()
{
    //freopen("475A.in","r",stdin);
    //freopen("475A.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<n;i++)c[a[i]]='O';
    printf("%s",c);
    return 0;
}