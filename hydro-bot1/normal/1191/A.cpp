// Hydro submission #625cee7181ef68d42bcbb363@1650257521812
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    switch(x%4)
    {
        case 0:printf("1 A\n");break;
        case 1:printf("0 A\n");break;
        case 2:printf("1 B\n");break;
        case 3:printf("2 A\n");break;
    }
    return 0;
}