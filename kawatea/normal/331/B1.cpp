#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[300000];
int b[300000];
long long bit[300001];

long long sum(int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    
    return s;
}

void add(int i, long long v)
{
    while (i <= n) {
        bit[i] += v;
        i += i & -i;
    }
}

int main()
{
    int q, i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        a[i]--;
        
        b[a[i]] = i;
    }
    
    for (i = 0; i < n - 1; i++) {
        if (b[i] > b[i + 1]) add(i + 1, 1);
    }
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        y--;
        z--;
        
        if (x == 1) {
            printf("%d\n", sum(z) - sum(y) + 1);
        } else {
            if (a[y] > 0 && b[a[y] - 1] > y && b[a[y] - 1] < z) {
                add(a[y], -1);
            }
            
            if (a[y] < n - 1 && b[a[y] + 1] > y && b[a[y] + 1] < z) {
                add(a[y] + 1, 1);
            }
            
            if (a[z] > 0 && b[a[z] - 1] > y && b[a[z] - 1] < z) {
                add(a[z], 1);
            }
            
            if (a[z] < n - 1 && b[a[z] + 1] > y && b[a[z] + 1] < z) {
                add(a[z] + 1, -1);
            }
            
            if (a[y] + 1 == a[z]) {
                add(a[z], 1);
            }
            
            if (a[y] - 1 == a[z]) {
                add(a[y], -1);
            }
            
            swap(a[y], a[z]);
            swap(b[a[y]], b[a[z]]);
        }
    }
    
    return 0;
}