#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a[6];
    for(int i = 0; i < 6; i++)
        scanf("%d", a + i);
    sort(a, a + 6);
    if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
        puts(a[4] == a[5] ? "Elephant" : "Bear");
    } else if(a[1] == a[2] && a[2] == a[3] && a[3] == a[4]) {
        puts("Bear");
    } else if(a[2] == a[3] && a[3] == a[4] && a[4] == a[5]) {
        puts(a[0] == a[1] ? "Elephant" : "Bear");
    } else {
        puts("Alien");
    }
}