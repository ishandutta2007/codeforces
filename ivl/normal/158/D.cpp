#include <cstdio>

using namespace std;

int n;
int t[20005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", t + i);
    }
    int rez = -1000000000;
    for (int i = 3; i <= n; ++i){
        if (n % i){
           continue;
        }
        int maks = -1000000000, pom;
        for (int j = 0; j < (n / i); ++j){
            pom = 0;
            for (int k = 0; k < i; ++k){
                pom += t[k * (n / i) + j];
            }
            if (pom > maks){
               maks = pom;
            }
        }
        if (maks > rez){
           rez = maks;
        }
    }
    printf("%d\n", rez);
    //while (true);
    return 0;
}