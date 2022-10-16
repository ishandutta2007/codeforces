#include <iostream>
#include <cstring>
using namespace std;
int n;
char s[1000];
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>s;
    int asd=strlen(s);
    if(asd>10)
    {
    cout<<s[0];
    cout<<asd-2;
    cout<<s[asd-1]<<'\n';
    }
    else cout<<s<<'\n';
}
    return 0;
}