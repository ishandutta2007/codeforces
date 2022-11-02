#include<bits/stdc++.h>
using namespace std;
string tab[1000005];
int tab1[1000005];
int tab2[1000005];
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
            cin>>tab[x];
        for(int x=0;x<a;x++)
        {
            tab1[x]=0;
            for(auto y:tab[x])
                if(y=='.')
                    tab1[x]++;
        }
        for(int x=0;x<b;x++)
        {
            tab2[x]=0;
            for(int y=0;y<a;y++)
                if(tab[y][x]=='.')
                    tab2[x]++;
        }
        int mini=1e9,pom;
        for(int x=0;x<a;x++)
            for(int y=0;y<b;y++)
            {
                if(tab[x][y]=='.')
                    pom=-1;
                else
                    pom=0;
                mini=min(mini,tab1[x]+tab2[y]+pom);
            }
        cout<<mini<<'\n';
    }
	return 0;
}