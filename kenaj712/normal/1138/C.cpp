#include<bits/stdc++.h>
using namespace std;
vector<int> wiersze[1005];
vector<int> kolumny[1005];
vector<int> wiersze2[1005];
vector<int> kolumny2[1005];
int tab[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
        {
            cin>>tab[x][y];
            wiersze[x].push_back(tab[x][y]);
            kolumny[y].push_back(tab[x][y]);
        }
    for(int x=0;x<a;x++)
    {
        sort(wiersze[x].begin(),wiersze[x].end());
        for(int y=0;y<b-1;y++)
            if(wiersze[x][y]!=wiersze[x][y+1])
                wiersze2[x].push_back(wiersze[x][y]);
        wiersze2[x].push_back(wiersze[x][b-1]);
    }
    for(int x=0;x<b;x++)
    {
        sort(kolumny[x].begin(),kolumny[x].end());
        for(int y=0;y<a-1;y++)
            if(kolumny[x][y]!=kolumny[x][y+1])
                kolumny2[x].push_back(kolumny[x][y]);
        kolumny2[x].push_back(kolumny[x][a-1]);
    }
    int pom1,pom2,pom3,pom4;
    for(int x=0;x<a;x++)
    {
        for(int y=0;y<b;y++)
        {
            pom1=wiersze2[x].size();
            pom2=lower_bound(wiersze2[x].begin(),wiersze2[x].end(),tab[x][y])-wiersze2[x].begin()+1;
            pom3=kolumny2[y].size();
            pom4=lower_bound(kolumny2[y].begin(),kolumny2[y].end(),tab[x][y])-kolumny2[y].begin()+1;
            cout<<max(pom2,pom4)+max(pom1-pom2,pom3-pom4)<<" ";
        }
        cout<<'\n';
    }
	return 0;
}