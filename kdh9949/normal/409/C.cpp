#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, d, e;
int ans = 100;

int main(){
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    ans = min(ans, a / 1);
        ans = min(ans, b / 1);
            ans = min(ans, c / 2);
                ans = min(ans, d / 7);
                    ans = min(ans, e / 4);
    printf("%d", ans);
}