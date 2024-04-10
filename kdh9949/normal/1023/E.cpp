#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second

const int N = 505;

int n, c;
char r[2 * N];

int q(int x, int y, int z, int w){
    printf("? %d %d %d %d\n", x, y, z, w);
    fflush(stdout);
    char res[5];
    scanf("%s", res);
    return res[0] == 'Y';
}

int main(){
    scanf("%d", &n);
    for(int a = 1, b = 1; a + b < n + 1; ){
        if(q(a, b + 1, n, n)){ r[c++] = 'R'; b++; }
        else{ r[c++] = 'D'; a++; }
    }
    c = 2 * n - 3;
    for(int a = n, b = n; a + b > n + 1; ){
        if(q(1, 1, a - 1, b)){ r[c--] = 'D'; a--; }
        else{ r[c--] = 'R'; b--; }
    }
    printf("! %s\n", r);
    fflush(stdout);
    return 0;
}