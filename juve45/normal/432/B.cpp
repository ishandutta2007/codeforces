#include <cstdio>
#include <vector>
#define DMAX 100001
using namespace std;

int x[DMAX], y[DMAX];
int n, a, b;
int main()
{
    scanf("%i", &n);
    for(int i=1;i<=n;i++)
        {scanf("%i%i", &a ,&b);
        y[i]=b;
        x[a]++;
        }
    for(int i=1;i<=n;i++)
        printf("%i %i\n", n-1+x[y[i]],n-1-x[y[i]]);

    return 0;
}