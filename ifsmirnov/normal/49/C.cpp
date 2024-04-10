#include <cstdio>
#include <vector>
using namespace std;

int n;
int main()
{
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1");
        return 0;
    }
    for (int i = 2; i <= n; i++)
        printf("%d ", i);
    printf("1");
    return 0;
};