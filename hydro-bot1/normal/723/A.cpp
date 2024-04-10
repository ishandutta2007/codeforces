// Hydro submission #62550d1fac286d0a56b86af0@1649741149201
#include<bits/stdc++.h>
using namespace std;
int m[3];
int main()
{
    for(int i=0;i<3;i++)
    cin>>m[i];sort(m,m+3);
    printf("%d\n",m[2]-m[0]);
    return 0;
}