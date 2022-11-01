#include <cstdio>
using namespace std;
bool rel(char c, char d) {
    return c - d == 1 || c - d == -2;
}
int main() {
    char c1 = getchar();
    char c2 = getchar();
    getchar();
    /* char c3 = */ getchar();
    char c4 = getchar();
    getchar();
    char d1 = getchar();
    char d2 = getchar();
    getchar();
    /* char d3 = */ getchar();
    char d4 = getchar();
    getchar();
    bool relc = c1 == 'X' ? rel(c2, c4) : rel(c1, c2 == 'X' ? c4 : c2);
    bool reld = d1 == 'X' ? rel(d2, d4) : rel(d1, d2 == 'X' ? d4 : d2);

    puts(relc == reld ? "YES" : "NO");
}