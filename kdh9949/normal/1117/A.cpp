#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], m, r;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    m = *max_element(a, a + n);
    for(int i = 0, j = 0; i < n; i++){
        if(a[i] == m) j++;
        else j = 0;
        r = max(r, j);
    }
    printf("%d\n", r);
}