#include <cstdio>
#include <cstring>
using namespace std;
char s[2001];
int main() {
    int n, m;
    scanf("%d %d %s", &n, &m, s);

    bool ok = false;
    for (int offset = 0; offset < m; offset++) {
        bool has_0 = false, has_1 = false;
        int ndot = 0;
        for (int i = offset; i < n; i += m) {
            has_0 = has_0 || s[i] == '0';
            has_1 = has_1 || s[i] == '1';
            ndot += s[i] == '.';
        }

        for (int i = offset; i < n; i += m)
            if (s[i] == '.') {
                if (has_0) {
                    s[i] = '1';
                    has_1 = true;
                } else {
                    s[i] = '0';
                    has_0 = true;
                }
            }
        
        if (has_0 && has_1)
            ok = true;
    }

    puts(ok ? s : "No");
}