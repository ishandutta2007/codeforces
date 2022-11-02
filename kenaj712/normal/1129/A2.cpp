#include<bits/stdc++.h>
using namespace std;
vector<int> tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    for(int x=0;x<b;x++)
    {
        cin>>c>>d;
        tab[c].push_back(d);
    }
    for(int x=1;x<=a;x++)
        sort(tab[x].begin(),tab[x].end());
    for(int x=1;x<=a;x++)
    {
        int maks=0;
        bool czy=false;
        for(int y=x;y!=x||czy==false;y=y%a+1)
        {
            czy=true;
            vector<int>::iterator it=lower_bound(tab[y].begin(),tab[y].end(),y);
            if(it==tab[y].end())
                it=tab[y].begin();
            if(tab[y].empty()==false)
                maks=max(maks,(int(tab[y].size())-1)*a+(y-x+a)%a+((*it)+a-y)%a);
        }
        cout<<maks<<" ";
    }
	return 0;
}