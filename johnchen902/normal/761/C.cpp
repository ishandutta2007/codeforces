#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;
int a1[50], a2[50], a3[50];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        char s[51];
        scanf("%s", s);
        a1[i] = a2[i] = a3[i] = 9999999;
        for(int j = 0; j < m; j++) {
            char c = s[j];
            if('0' <= c && c <= '9')
                a1[i] = min(a1[i], min(j, m - j));
            if('a' <= c && c <= 'z')
                a2[i] = min(a2[i], min(j, m - j));
            if(c == '#' || c == '*' || c == '&')
                a3[i] = min(a3[i], min(j, m - j));
        }
    }
    int ans = 9999999;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
                for(int k = 0; k < n; k++)
                    if(i != k && j != k)
                        ans = min(ans, a1[i] + a2[j] + a3[k]);
    printf("%d\n", ans);
}