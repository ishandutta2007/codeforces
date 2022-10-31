// Hydro submission #6257a031ac286d0a56ba98e7@1649909809123
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i;
    char c,s;
    cin>>n>>a>>b;
    if(a==b)
    {
        printf("0\n");
        return 0;
    }
    if(a>b) swap(a,b);
    for(i=1;i<=a;i++)
    cin>>c;
    for(i=a+1;i<=b;i++)
    cin>>s;
    printf("%d\n",!(c==s));
    return 0;
}