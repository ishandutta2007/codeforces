#include <iostream>

using namespace std;

int n, m, a, b;
string s;
int main()
{

cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>s>>a>>b;
    if(b>a && a>=2400)
    {
        cout<<"YES\n";
        return 0;
    }
}
cout<<"NO\n";

    return 0;
}