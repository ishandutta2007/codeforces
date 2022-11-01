#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int x, y, z;
int p;
int in[100005][2];

void rotate(){
     for (int i = 0; i < p; ++i){
         swap(in[i][0], in[i][1]);
         in[i][1] = n + 1 - in[i][1];
     }
     swap(n, m);
}

int main(){
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
    for (int i = 0; i < p; ++i) scanf("%d%d", in[i], in[i] + 1);
    x &= 3;
    y &= 1;
    z &= 3;
    for (int i = 0; i < x; ++i) rotate();
    if (y) for (int i = 0; i < p; ++i) in[i][1] = m + 1 - in[i][1];
    for (int i = 0; i < z * 3; ++i) rotate();
    for (int i = 0; i < p; ++i) printf("%d %d\n", in[i][0], in[i][1]);
    return 0;
}