#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,ans=0;
    cin>>n;
    map <string , long > mp;
    string x;
    while(n--)
    {
        cin>>x;
        mp[x]++;
    }
    ans+=mp["Tetrahedron"]*4;
    ans+=mp["Cube"]*6;
    ans+=mp["Octahedron"]*8;
    ans+=mp["Dodecahedron"]*12;
    ans+=mp["Icosahedron"]*20;
    cout<<ans;
    return 0;
}