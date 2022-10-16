#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
cin>>a>>b>>c;
cin>>d>>e>>f;

int l=b+c+d;
int number=l*l;

int m=b*b+d*d+f*f;

cout<<number-m<<'\n';

return 0;
}