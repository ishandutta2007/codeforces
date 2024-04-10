#include <cstdio>

using namespace std;

int n;
char polje[100];

int main(){
    scanf("%d%s", &n, polje);
    int rez = 0;
    for (int i = 1; i < n; ++i){
        if (polje[i] == polje[i - 1]){
           ++rez;
        }
    }
    printf("%d\n", rez);
    return 0;
}