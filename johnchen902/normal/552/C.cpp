#include <cstdio>

bool ok(int w, int m) {
    if(w == 2)
        return true;
    while(m) {
        int k = m % w;
        m /= w;
        if(k != 0 && k != 1 && k != w - 1)
            return false;
        if(k == w - 1)
            m++;
    }
    return true;
}

int main() {
    int w, m;
    scanf("%d %d", &w, &m);
    puts(ok(w, m) ? "YES" : "NO");
}