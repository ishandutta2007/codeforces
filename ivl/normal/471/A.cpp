#include <cstdio>

using namespace std;

int x[10];
int y[20];

int main(){
    for (int i = 0; i < 6; ++i){
        scanf("%d", x + i);
        ++y[x[i]];
    }
    int a = -1, b = -1, c = -1;
    for (int i = 0; i < 20; ++i){
        if (y[i] >= 4){c = i; continue;}
        if (y[i] == 0) continue;
        b = a;
        a = i;
    }
    if (c != -1 && y[c] == 6){printf("Elephant\n"); return 0;}
    if (a == -1 || c == -1){printf("Alien\n"); return 0;}
    if (b != -1 || y[c] != 4){printf("Bear\n"); return 0;}
    if (y[a] == 2) printf("Elephant\n");
    else printf("Alien\n");
    return 0;
}