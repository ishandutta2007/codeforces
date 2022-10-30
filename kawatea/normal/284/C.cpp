#include <cstdio>

using namespace std;

long long bit[2][200002];

long long sum(int x, int i)
{
    long long s = 0;
    
    while (i > 0) {
        s += bit[x][i];
        i -= i & -i;
    }
    
    return s;
}

void add(int x, int i, long long v)
{
    while (i <= 200001) {
        bit[x][i] += v;
        i += i & -i;
    }
}

long long get(int x, int y)
{
    long long s = 0;
    
    s += sum(0, y + 1) + sum(1, y + 1) * (y + 1);
    s -= sum(0, x) + sum(1, x) * x;
    
    return s;
}

void set(int x, int y, long long z)
{
    add(0, x + 1, -z * x);
    add(1, x + 1, z);
    add(0, y + 2, z * (y + 1));
    add(1, y + 2, -z);
}

int main()
{
    int n, p = 0, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x == 1) {
            int y, z;
            
            scanf("%d %d", &y, &z);
            
            set(0, y - 1, z);
        } else if (x == 2) {
            int y;
            
            scanf("%d", &y);
            
            p++;
            
            set(p, p, y);
        } else {
            set(p, p, -get(p, p));
            
            p--;
        }
        
        printf("%.12lf\n", (double)get(0, p) / (p + 1));
    }
    
    return 0;
}