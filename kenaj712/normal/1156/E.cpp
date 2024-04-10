#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int where[1000005];
set<int> s;
set<int>::iterator it;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        where[tab[x]]=x;
    }
    s.insert(0);
    s.insert(a+1);
    long long licz=0;
    for(int x=a;x>=1;x--)
    {
        int pom1,pom2,pom3;
        pom2=where[x];
        pom3=*s.upper_bound(pom2);
        pom3--;
        it=s.upper_bound(pom2);
        it--;
        pom1=(*it)+1;
        if(pom2-pom1<pom3-pom2)
        {
            for(int y=pom1;y<pom2;y++)
                if(where[x-tab[y]]>pom2&&where[x-tab[y]]<=pom3)
                    licz++;
        }
        else
        {
            for(int y=pom2+1;y<=pom3;y++)
                if(where[x-tab[y]]>=pom1&&where[x-tab[y]]<pom2)
                    licz++;
        }
        s.insert(pom2);
    }
    cout<<licz;


	return 0;
}