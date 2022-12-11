#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int test; scanf("%d", &test);
    static char s[110];
    while(test --) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        sort(s + 1, s + n + 1);
        bool tag = (s[1] >= 'a' && s[1] <= 'z');
        for(int i = 2; i <= n; i ++) {
            if(s[i] != s[i - 1] + 1 || !(s[i] >= 'a' && s[i] <= 'z')) {
                tag = 0; break ;
            }
        }
        puts(tag ? "Yes" : "No");
    }
    return 0;
}