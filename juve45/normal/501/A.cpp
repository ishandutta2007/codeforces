#include <iostream>

using namespace std;

int a, b, c, d;

int main()
{
cin>>a>>b>>c>>d;

int s1=max(3*a/10, a-(a*c/250));
int s2=max(3*b/10, b-(b*d/250));

if(s1>s2) cout<<"Misha\n";
if(s1==s2) cout<<"Tie\n";
if(s1<s2) cout<<"Vasya\n";

    return 0;

}