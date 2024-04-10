#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int e = 0, h = 0, c = 0;
    while(n--) {
        int x;
        scanf("%d", &x);
        e += (h - x);
        if(e < 0) {
            c -= e;
            e = 0;
        }
        h = x;
    }
    printf("%d\n", c);
}