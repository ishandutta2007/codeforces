#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[200005];
bool bio[1000005];
int maks[1000005];
int acc(int x){if (x > 1000000) x = 1000000; return maks[x];}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
        maks[a[i]] = a[i];
    }
    for (int i = 1; i <= 1000000; ++i){
        maks[i] = max(maks[i], maks[i - 1]);
    }
    int r = 0;
    for (int i = 0; i < n; ++i){
        int x = a[i];
        if (bio[x]++) continue;
        for (int j = 2 * x; j <= 2000000; j += x){
            int y = acc(j - 1);
            r = max(r, y - j + x);
        }
    }
    printf("%d\n", r);
    return 0;
}