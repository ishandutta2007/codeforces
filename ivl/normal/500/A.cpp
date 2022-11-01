#include <cstdio>

using namespace std;

int n, t;
bool bio[100005];

int main(){
    scanf("%d%d", &n, &t);
    bio[1] = true;
    for (int i = 1; i <= n - 1; ++i){
        int a; scanf("%d", &a);
        if (bio[i]) bio[a + i] = true;
    }
    if (bio[t]) printf("YES\n"); else printf("NO\n");
    return 0;
}