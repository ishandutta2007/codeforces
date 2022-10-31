#include <cstdio>
using namespace std;
int main(){
    int a, b, c, d, e, f, g;
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
    puts((a + b + c + 4) / 5 + (d + e + f + 9) / 10 <= g ? "YES" : "NO");
}