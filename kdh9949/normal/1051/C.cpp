#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second

const int N = 105;

int n, a[N], c[N], w[N], ww[N], j, jj;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
        c[a[i]]++;
    }
    for(int i = 1; i <= 100; i++){
        if(c[i] == 2) continue;
        else if(c[i] == 1){
            w[i] = j;
            j ^= 1;
        }
        else if(c[i] > 2){
            ww[i] = -1;
            jj = i;
        }
    }
    if(j){
        if(!jj){ puts("NO"); return 0; }
        ww[jj] = 0;
        w[jj] = 1;
    }
    puts("YES");
    for(int i = 0; i < n; i++){
        if(ww[a[i]] < 0) putchar('A');
        else if(!ww[a[i]]){
            putchar('A' + w[a[i]]);
            ww[a[i]] = 1;
            w[a[i]] ^= 1;
        }
        else putchar('A' + w[a[i]]);
    }
    puts("");
    return 0;
}