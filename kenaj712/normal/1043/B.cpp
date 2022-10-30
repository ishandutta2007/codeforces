#include<bits/stdc++.h>
using namespace std;
int tab[1005];
vector<int> v;
vector<int> v2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        v.push_back(tab[x]-tab[x-1]);
    }
    for(int x=1;x<=a;x++)
    {
        bool czy=false;
        for(int y=0;y<a;y++)
        {
            if(v[y]!=v[y%x])
                czy=true;
        }
        if(czy==false)
            v2.push_back(x);
    }
    cout<<v2.size()<<'\n';
    for(int x=0;x<v2.size();x++)
        cout<<v2[x]<<" ";
	return 0;
}