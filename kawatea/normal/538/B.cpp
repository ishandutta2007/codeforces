#include <cstdio>
#include <vector>

using namespace std;

int get(int n)
{
    int sum = 0, x = 1;
    
    while (n) {
        if (n % 10 != 0) sum += x;
        x *= 10;
        n /= 10;
    }
    
    return sum;
}

int main()
{
    int n, i;
    vector <int> v;
    
    scanf("%d", &n);
    
    while (n) {
        int x = get(n);
        
        n -= x;
        v.push_back(x);
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", v[i]);
    }
    
    puts("");
    
    return 0;
}