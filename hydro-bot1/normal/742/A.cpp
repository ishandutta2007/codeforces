// Hydro submission #62550f0417cd4d0a41764e0f@1649741572598
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n) switch(n%4)
    {
        case 0:printf("6\n");break;
        case 1:printf("8\n");break;
        case 2:printf("4\n");break;
        case 3:printf("2\n");break;
    }
    else printf("1\n");
    return 0;
}