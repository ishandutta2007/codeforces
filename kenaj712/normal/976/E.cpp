#include<bits/stdc++.h>
using namespace std;
long long tab[1000005][2];
vector <pair<long long,long long> > v;
bool odw[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c;
    cin>>a>>b>>c;

    c=min(c,a);
    long long pot=1;
    for(int x=0;x<b;x++)
        pot*=2;
    long long ile=0,maks,koniec=0;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x][0]>>tab[x][1];
        swap(tab[x][0],tab[x][1]);
        ile+=tab[x][0];
        v.push_back(make_pair(tab[x][1]-tab[x][0],x));
    }
    sort(v.begin(),v.end());

    bool czy=false;
    for(int x=a-1;x>=a-c;x--)
    {
        if(v[x].first>0)
        {
             ile+=v[x].first;
            odw[v[x].second]=true;
        }
        else
            czy=true;
    }
    if(czy==false)
        koniec=v[a-c].first;
    //for(int x=0;x<a;x++)
      //  cout<<v[x].first<<" "<<v[x].second<<'\n';
    maks=ile;
    for(int x=1;x<=a;x++)
    {
        if(odw[x]==true)
            maks=max(maks,ile-tab[x][1]+tab[x][0]+tab[x][1]*pot-tab[x][0]);
        else
            maks=max(maks,ile-koniec+tab[x][1]*pot-tab[x][0]);
    }
    if(c!=0)
        cout<<maks;
    else
        cout<<ile;
    return 0;
}