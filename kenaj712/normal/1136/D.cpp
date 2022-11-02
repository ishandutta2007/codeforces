#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> s;
set<int> s2;
int tab[1000005];
bool ok[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    while(b--)
    {
        cin>>c>>d;
        s.insert(make_pair(c,d));
    }
    s2.insert(tab[a]);
    int licz=0;
    bool czy;
    for(int x=a-1;x>=1;x--)
    {
        czy=true;
        for(auto y:s2)
            if(s.find(make_pair(tab[x],y))==s.end())
            {
                czy=false;
                break;
            }
        if(czy==true)
            licz++;
        else
            s2.insert(tab[x]);
    }
    cout<<licz;


	return 0;
}