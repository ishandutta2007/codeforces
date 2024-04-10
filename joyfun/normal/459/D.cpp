#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int lowbit(int x) {
    return (x&(-x));
}

const int N = 1000005;
int n, bit[N], bit2[N], save[N], bit3[N];
struct Num {
    int a, b, id;
} nu[N];

void add(int *bit, int x, int v) {
    while (x < N) {
        bit[x] += v;
        x += lowbit(x); 
    }
}

int get(int *bit, int x) {
    int ans = 0;
    while (x) {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

bool cmp1(Num a, Num b) {
return a.a < b.a;
}

bool cmp2(Num a, Num b) {
return a.id < b.id;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nu[i].a);
        nu[i].id = i;   
    }
    sort(nu, nu + n, cmp1);
    int cnt = 1;
    nu[0].b = 1;
    for (int i = 1; i < n; i++) {
        if (nu[i].a != nu[i - 1].a)
            cnt++;
        nu[i].b = cnt;
    }
    sort(nu, nu + n, cmp2);
    for (int i = 0; i < n; i++) {
        add(bit, nu[i].b, 1);
        add(bit2, get(bit, nu[i].b) - get(bit, nu[i].b - 1), 1);
    }
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        add(bit2, get(bit, nu[i].b) - get(bit, nu[i].b - 1), -1);
        add(bit, nu[i].b, -1);
        add(bit3, nu[i].b, 1);
        int tmp = get(bit3, nu[i].b) - get(bit3, nu[i].b - 1);
        ans += get(bit2, n) - get(bit2, tmp);
        
    }
    printf("%lld\n", ans);
    //system("pause");
    return 0;
}