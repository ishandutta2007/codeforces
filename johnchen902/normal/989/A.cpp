#include <cstdio>
#include <cstring>
using namespace std;
char s[101];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    bool ans = false;
    for (int i = 1; i + 1 < n; i++) {
        bool a = (s[i - 1] == 'A' || s[i] == 'A' || s[i + 1] == 'A');
        bool b = (s[i - 1] == 'B' || s[i] == 'B' || s[i + 1] == 'B');
        bool c = (s[i - 1] == 'C' || s[i] == 'C' || s[i + 1] == 'C');
        if (a && b && c)
            ans = true;
    }
    puts(ans ? "Yes" : "No");
}