#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b,c="",d="",e;
    cin>>a>>b;
    set<string> s;
    for(int x=0;x<a.size();x++)
    {
        c+=a[x];
        for(int y=0;y<b.size();y++)
        {
            d+=b[y];
            s.insert(c+d);
        }
        d="";
    }
    cout<<*s.begin();
    return 0;
}