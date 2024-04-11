#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>

using namespace std;

int main()
{
    int a, b, d1 = 0, d2 = 0, d3 = 0;
    scanf("%d%d", &a, &b);
    for(int i=1; i<7; i++)
    {
        if(abs(i-a)==abs(i-b))
            d2++;
        if(abs(i-a)>abs(i-b))
            d3++;
        if(abs(i-a)<abs(i-b))
            d1++;
    }
    printf("%d %d %d", d1, d2, d3);
}