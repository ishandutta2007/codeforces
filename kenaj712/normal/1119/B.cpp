#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
multiset<int> s;
multiset<int>::iterator it;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    for(int x=1;x<=a;x++)
    {
        for(int y=0;y<x;y++)
            s.insert(tab[y]);
        int pom=b,pom2,pom3;
        while(0==0)
        {
            if(s.empty()==true)
                break;
            it=s.end();
            it--;
            pom3=*it;
            if(*it>pom)
            {
                cout<<x-1;
                return 0;
            }
            pom-=pom3;
            s.erase(it);
            if(s.empty()==false)
            {
                it=s.end();
                it--;
                s.erase(it);
            }
            else
                break;
        }
    }
    cout<<a;
	return 0;
}