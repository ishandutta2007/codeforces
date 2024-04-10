#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int b, k, r, a[N];

int main(){
    scanf("%d%d", &b, &k);
    b %= 2;
    for(int i = 0; i < k; i++){
        scanf("%d", a + i);
        a[i] %= 2;
    }
    reverse(a, a + k);
    for(int i = 0, j = 1; i < k; i++, j *= b){
        r ^= (a[i] * j);
    }
    puts(r ? "odd" : "even");
}