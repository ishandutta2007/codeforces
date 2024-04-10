#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d" , &n);
    int sum = 0;
    for(int i=1 ; i<n ; i++)
        if(n%i == 0)
            sum++;
    printf("%d" , sum);
    return 0;
}