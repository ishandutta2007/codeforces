#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n;
    char name[4];
    scanf("%d %s", &n, name);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        char t[100];
        scanf("%s", t);
        if(strncmp(name, t, 3) == 0)
            a++;
        else
            b++;
    }
    puts(a > b ? "contest" : "home");
}