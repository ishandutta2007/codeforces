#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    string d,e="";
    cin>>d;
    cout<<a<<'\n';
    for(int x=0;x<a;x++)
        e+=d[x%b];
    if(e>=d)
        cout<<e;
    else
    {
        e="";
        for(int x=b-1;x>=0;x--)
        {
            if(d[x]!='9')
            {
                d[x]++;
                break;
            }
            d[x]='0';
        }
        for(int x=0;x<a;x++)
            e+=d[x%b];
        cout<<e;
    }
	return 0;
}