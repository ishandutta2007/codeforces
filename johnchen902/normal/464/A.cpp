#include <cstdio>
#include <algorithm>
using namespace std;
char s[1001];
int main(){
    int n, p;
    scanf("%d %d %s", &n, &p, s);
    bool found = false;
    for(int i = n - 1; i >= 0; i--) {
        // can we modify s[i]?
        char c;
        for(c = s[i] + 1; c < 'a' + p; c++) {
            if(i >= 1 && c == s[i - 1]) continue;
            if(i >= 2 && c == s[i - 2]) continue;
            found = true; break;
        }
        if(found) {
            s[i] = c;
            for(i++; i < n; i++) {
                char d;
                for(d = 'a'; d < 'a' + p; d++) {
                    if(i >= 1 && d == s[i - 1]) continue;
                    if(i >= 2 && d == s[i - 2]) continue;
                    s[i] = d; break;
                }
            }
            break;
        }
    }
    if(found)
        puts(s);
    else
        puts("NO");
}