#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for (int x = 4; ; x += 2){
        int y = n - x;
        if (y % 3 == 0){printf("%d %d\n", x, y); return 0;}
    }
    return 0;
}