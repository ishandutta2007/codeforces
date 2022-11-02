#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int where[1000005];
bool ok[1000005];
bool zajete[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,t;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        where[tab[x]]=x;
    }
    t=a;
    int licz=0;
    ok[0]=true;
    while(t--)
    {
        cin>>c;
        zajete[where[c]]=true;
        if(ok[where[c]-1]==false)
            licz++;
        int pom=where[c];
        while(zajete[pom]==true&&ok[pom-1]==true)
        {
            ok[pom]=true;
            pom++;
        }
    }
    cout<<licz;

	return 0;
}