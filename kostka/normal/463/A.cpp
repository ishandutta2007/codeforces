//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    int res = -1;
    while(n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a<=s && b==0)
        {
            res = max(res,0);
        }
        else if(a<s)
        {
            res = max(res,100-b);
        }
    }
    printf("%d\n", res);
    
    return 0;
}