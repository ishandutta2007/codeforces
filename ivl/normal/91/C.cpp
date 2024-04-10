#include <cstdio>

using namespace std;

int gr[100005];
int un(int a){if (gr[a] == a) return a; return gr[a] = un(gr[a]);}
int SOL = 1;
void join(int a, int b){a = un(a), b = un(b); if (a == b) SOL = (2 * SOL) % 1000000009; gr[a] = b;}
int n, m;

int main(){
    for (int i = 0; i <= 100000; ++i) gr[i] = i;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){int a, b; scanf("%d%d", &a, &b); join(a, b); printf("%d\n", SOL - 1);} ///
    return 0;
}