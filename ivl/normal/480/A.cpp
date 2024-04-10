#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;

int n;
pair < int, int > ab[5005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d%d", &(ab[i].x), &(ab[i].y));
    }
    sort(ab, ab + n);
    int R = ab[0].y;
    for (int i = 1; i < n; ++i){
        if (ab[i].y >= R) R = ab[i].y; else R = ab[i].x;
    }
    printf("%d\n", R);
    return 0;
}