#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    s *= 100;
    int maxi = -1;
    while(n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x * 100 + y <= s) {
            maxi = max(maxi,
                    (100 - y) % 100);
        }
    }
    printf("%d\n", maxi);
}