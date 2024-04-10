#include <cstdio>
#include <algorithm>

using namespace std;

int v[] = {1,1,2,7,4};

int main(){
    int r = 1000000;
    for (int i = 0; i < 5; ++i){
        int a;
        scanf("%d", &a);
        a /= v[i];
        r = min(r, a);
    }
    printf("%d\n", r);
    
    return 0;
}