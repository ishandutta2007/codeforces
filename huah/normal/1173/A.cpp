#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a+c>=b&&b+c>=a&&c!=0) printf("?\n");
    else if(a>b) printf("+");
    else if(b>a) printf("-");
    else if(b==a) printf("0\n");
}