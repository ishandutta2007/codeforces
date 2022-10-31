// Hydro submission #62591e7637de167dd82bca09@1650007676316
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int i=1;
    printf("%c",a[0]);
    while(a[i]<b[0]&&i<a.size())
    printf("%c",a[i]),i++; 
    printf("%c",b[0]);
    return 0;
}