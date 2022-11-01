#include <cstdio>
using namespace std;
int main() {
    char s[3];
    scanf("%s", s);
    int x = 0;
    if(s[0] == 'a' || s[0] == 'h')
        x++;
    if(s[1] == '1' || s[1] == '8')
        x++;
    printf("%d\n", x == 0 ? 8 : x == 1 ? 5 : 3);
}