#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll cnt,ccnt;
string str;
map<string,ll>mp={{"Tetrahedron",4},{"Cube",6},{"Octahedron",8},{"Dodecahedron",12},{"Icosahedron",20}};
int main()
{
    cin>>cnt;
    for(register int i=0;i<cnt;i++)
    {
        cin>>str;
        ccnt+=mp[str];
    }
    cout<<ccnt;
}