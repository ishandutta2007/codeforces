#include <iostream>
#include <map>
using namespace std;

int n, m1;
map <string, string> m;
string a, b;
int main()
{
    cin>>n>>m1;

    for(int i=1;i<=m1;i++)
    {
        cin>>a>>b;
        if(a.size()>b.size())
            m[a]=b;
        else m[a]=a;
    }
    for(int i=1;i<=n;i++)
        cin>>a, cout<<m[a]<<' ';

return 0;
}