#include <cstdio>
#include <algorithm>
using namespace std;
bool v[1000000];
int main() {
    int n;
    scanf("%d", &n);
    int m = 0, c = 0;
    for(int i = 0; i < n; i++) {
        char s[2];
        int x;
        scanf("%1s %d", s, &x);
        x--;
        if(*s == '+')
            v[x] = true, m = max(m, ++c);
        else if(v[x])
            v[x] = false, c--;
        else
            m++;
    }
    printf("%d\n", m);
}