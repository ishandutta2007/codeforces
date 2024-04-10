#include <cstdio>

using namespace std;

int dx[256], dy[256];

int a, b;
char s[105];

bool f(int a, int b, int c, int d){
     if (a == 0){
        if (b != 0) return false;
        if (c == 0){
           if (d != 0) return false;
           return true;
        }
        if (d % c != 0) return false;
        if (d / c < 0) return false;
        return true;
     }
     if (c == 0) return f(c, d, a, b);
     if (b % a != 0) return false;
     if (d % c != 0) return false;
     if (b / a < 0) return false;
     if (b / a == d / c) return true;
     return false;
}

int main(){
    dy['U'] = 1;
    dy['D'] = -1;
    dx['L'] = -1;
    dx['R'] = 1;
    scanf("%d%d%s", &a, &b, s);
    int sx = 0, sy = 0;
    int l = 0;
    while (s[l] != '\0') ++l;
    for (int i = 0; i < l; ++i){sx += dx[s[i]]; sy += dy[s[i]];}
    int px = 0, py = 0;
    bool ch = false;
    for (int i = 0; i < l; ++i){
        ch |= f(sx, a - px, sy, b - py);
        px += dx[s[i]];
        py += dy[s[i]];
    }
    if (ch) printf("Yes\n");
    else printf("No\n");
    return 0;
}