#include <cstdio>

using namespace std;

int n;
int niz[100005];
long long rez;

int main(){
    scanf("%d", &n);
    scanf("%d", niz);
    for (int i = 1; i < n; ++i){
        scanf("%d", niz + i);
        if (niz[i] < niz[i - 1]){
           rez += niz[i - 1] - niz[i];
        }
    }
    printf("%I64d\n", rez);
    return 0;
}