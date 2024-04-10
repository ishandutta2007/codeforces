#include <cstdio>
using namespace std;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int day = 1;
    while(true) {
        if(n == 0) break;
        n--;
        if(day % m == 0) n++;
        day++;
    }
    printf("%d\n", day - 1);
}