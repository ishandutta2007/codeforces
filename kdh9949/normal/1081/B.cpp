#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define X first
#define Y second

const int N = 100005;

int n, b[N], r[N];
pii a[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i].X);
        a[i].Y = i;
    }
    sort(a, a+n);
    for(int i = 0, c = 1; i < n; ){
        int t = n - a[i].X;
        if(i + t > n){ puts("Impossible"); return 0; }
        for(int j = 0; j < t; j++){
            if(a[i+j].X != a[i].X){ puts("Impossible"); return 0; }
            b[i+j] = c;
        }
        c++;
        i += t;
    }
    puts("Possible");
    for(int i = 0; i < n; i++) r[a[i].Y] = b[i];
    for(int i = 0; i < n; i++) printf("%d ", r[i]);
}