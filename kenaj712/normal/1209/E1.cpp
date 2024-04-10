#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
vector<int> v2;
int tab[15][1000005];
int maksi=0;
void rek(int where,int a)
{
    if(where==v2.size())
    {
        int suma=0,maks;
        for(int x=0;x<a;x++)
        {
            maks=0;
            for(auto y:v2)
                maks=max(maks,tab[x][y]);
            suma+=maks;
        }
        maksi=max(maksi,suma);
        return;
    }
    int t=a,y=v2[where];
    while(t--)
    {
        rek(where+1,a);
        for(int x=a-1;x>=1;x--)
            swap(tab[x-1][y],tab[x][y]);
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        for(int x=0;x<a;x++)
            for(int y=0;y<b;y++)
                cin>>tab[x][y];
        for(int y=0;y<b;y++)
        {
            int maks=0;
            for(int x=0;x<a;x++)
                maks=max(maks,tab[x][y]);
            v.push_back(make_pair(maks,y));
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int x=0;x<v.size();x++)
        {
            v2.push_back(v[x].second);
            if(x==a-1)
                break;
        }
        rek(0,a);
        cout<<maksi<<'\n';
        maksi=0;
        v.resize(0);
        v2.resize(0);
    }
	return 0;
}