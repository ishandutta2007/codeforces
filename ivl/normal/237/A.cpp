#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int n;
map < int, int > M;

int main(){
    scanf("%d", &n);
    int r = 0;
    for (int i = 0; i < n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        r = max(r, ++M[a * 100 + b]);
    }
    printf("%d\n", r);
    return 0;
}