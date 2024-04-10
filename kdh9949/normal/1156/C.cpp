#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k, a[N];

int f(int x){
    for(int i = 0; i < x; i++){
        if(a[n - x + i] - a[i] < k) return 0;
    }
    return 1;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int s = 0, e = n / 2;
    while(s <= e){
        int m = (s + e) / 2;
        if(f(m)) s = m + 1;
        else e = m - 1;
    }
    printf("%d\n", e);
}