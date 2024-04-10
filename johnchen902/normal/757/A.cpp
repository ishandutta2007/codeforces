#include <cstdio>
#include <map>
using namespace std;
template<typename T>
void minify(T &lhs, const T &rhs) {
    if(lhs > rhs)
        lhs = rhs;
}
char s[100001];
int main() {
    scanf("%s", s);
    map<char, int> mp;
    for(char *t = s; *t; t++)
        mp[*t]++;
    int ans = 100000;
    minify(ans, mp['B']);
    minify(ans, mp['u'] / 2);
    minify(ans, mp['l']);
    minify(ans, mp['b']);
    minify(ans, mp['a'] / 2);
    minify(ans, mp['s']);
    minify(ans, mp['r']);
    printf("%d\n", ans);
}