#include<bits/stdc++.h>
using namespace std;
vector<int> polaczenia[1000005];
vector<int> v[1000005];
bool odw[1000005];
int odl[1000005];
bool odw2[1000005];
int ojciec[1000005];
void dfs(int a,int b,int c)
{
    odw[a]=true;
    odl[a]=b;
    ojciec[a]=c;
    for(int x=0;x<polaczenia[a].size();x++)
        if(odw[polaczenia[a][x]]==false)
            dfs(polaczenia[a][x],b+1,a);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,c,d,e,f;
	cin>>a;
    for(int x=0;x<a-1;x++)
    {
        cin>>c>>d;
        polaczenia[c].push_back(d);
        polaczenia[d].push_back(c);
    }
    cin>>d;

    dfs(1,0,0);
    c=d;
    odw2[1]=true;
    bool czy=true;
    if(d!=1)
        czy=false;
    v[0].push_back(1);
    int poziom=0,indeks=0;
    for(int x=1;x<a;x++)
    {
        cin>>d;
        v[odl[d]].push_back(d);
        if(odl[d]-odl[c]<0||odl[d]-odl[c]>1||odw2[d]==true)
        {
            czy=false;
            break;
        }
        if(odl[d]-poziom>1)
        {
             poziom++;
             indeks=0;
        }

        while(indeks!=v[poziom].size()&&ojciec[d]!=v[poziom][indeks])
            indeks++;
        if(indeks==v[poziom].size())
        {
            czy=false;
            break;
        }

        c=d;
        odw2[d]=true;
    }
    if(czy==true)
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}