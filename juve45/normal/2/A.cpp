#include <iostream>
#include <map>
#include <string>
#define dmax 1001

using namespace std;

int main()
{
    map<string, int> f, g;
    string s[dmax];
    int c[dmax], n;
    int i,m=0;

    cin>>n;

    for(i=0; i<n; i++)
    {
        cin>>s[i]>>c[i];
        f[s[i]] += c[i];
    }

    for(i=0; i<n; i++)
        if(m<f[s[i]])
            m=f[s[i]];
    for(i=0; f[s[i]]<m || (g[s[i]]+=c[i])<m; i++);
    cout<<s[i];
    return 0;
}