#include <cstdio>

using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0, i = 1;
    while (n){
          ++cnt;
          --n;
          if (i % m == 0) ++n;
          ++i;
    }
    printf("%d\n", cnt);
    return 0;
}