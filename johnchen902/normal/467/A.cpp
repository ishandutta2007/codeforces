#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int x = 0;
    while(n--) {
        int y, z;
        scanf("%d %d", &y, &z);
        if(z - y >= 2)
            x++;
    }
    printf("%d\n", x);
}