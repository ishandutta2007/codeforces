// Hydro submission #6247f9200bc575b66aa58517@1648884001131
#include<bits/stdc++.h>
using namespace std;
bool w(char x,char y,char z)
{
    if(x=='r'&&y=='s'&&z=='s'
    ||x=='s'&&y=='p'&&z=='p'
    ||x=='p'&&y=='r'&&z=='r')
    return true;
    return false;
}
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    if(w(a[0],b[0],c[0])) printf("F\n");
    else if(w(b[0],c[0],a[0])) printf("M\n");
    else if(w(c[0],a[0],b[0])) printf("S\n");
    else printf("?\n");
    return 0;
}