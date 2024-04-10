#include <iostream>
#include <map>

#define DMAX 1001

using namespace std;

map <string, int> m;

string a[DMAX], b[DMAX];

int main()
{
    int k=0, n;
    string s1, s2;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s1>>s2;
        if(m.find(s1)==m.end())
        {
            m[s1]=++k;
            a[k]=s1;
            b[k]=s2;
        }
        else
            b[m[s1]]=s2;
            m[s2]=m[s1];
    }

    cout<<k<<'\n';
    for(int i=1; i<=k; i++)
        cout<<a[i]<<' '<<b[i]<<'\n';
    return 0;
}