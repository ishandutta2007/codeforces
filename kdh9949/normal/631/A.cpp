#include <cstdio>
#include <algorithm>
using namespace std;

int n, c, a, b;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &c);
        a |= c;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &c);
        b |= c;
    }
    printf("%d", a + b);
}