#include <cstdio>
#include <cstring>
using namespace std;
char s[9999];
bool found[26];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    bool bad = false;
    for(int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if(c && !found[c - 1])
            bad = true;
        found[c] = true;
    }
    puts(bad ? "NO" : "YES");
}