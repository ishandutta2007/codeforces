#include<bits/stdc++.h>
using namespace std;
set<pair<pair<int,int> ,pair<int,int>>> s;
vector<pair<pair<int,int> ,pair<int,int>>> v;
int tab[1005][2];
long long f(long long a)
{
    return a*(a-1)/2;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,pom1,pom2,pom3,pom4,pom5,pom6,pom7,pom8;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x][0]>>tab[x][1];
    for(int x=1;x<=a;x++)
        for(int y=x+1;y<=a;y++)
        {
            pom1=tab[x][1]-tab[y][1];
            pom2=tab[x][0]-tab[y][0];
            pom3=__gcd(pom1,pom2);
            if(pom1==0||pom2==0)
                pom3=0;
            if(pom3!=0)
            {
                pom4=pom1/pom3;
                pom5=pom2/pom3;
                if(pom4<0)
                {
                    pom4*=-1;
                    pom5*=-1;
                }
            }
            else
            {
                if(pom1==0)
                {
                    pom4=0;
                    pom5=1;
                }
                else
                {
                    pom4=1;
                    pom5=0;
                }
            }
            pom6=tab[x][1]*(tab[x][0]-tab[y][0])-tab[x][0]*(tab[x][1]-tab[y][1]);
            pom7=tab[x][0]-tab[y][0];
            pom8=__gcd(pom6,pom7);
            if(pom6==0||pom7==0)
                pom8=0;
            if(pom8!=0)
            {
                pom6=pom6/pom8;
                pom7=pom7/pom8;
                if(pom6<0)
                {
                    pom6*=-1;
                    pom7*=-1;
                }
            }
            else
            {
                if(pom6==0)
                {
                    pom6=0;
                    pom7=1;
                }
                else
                {
                    pom6=tab[x][0];
                    pom7=0;
                }
            }
            s.insert(make_pair(make_pair(pom4,pom5),make_pair(pom6,pom7)));
        }
    long long licz=0;
    licz+=f(s.size());
    for(auto x:s)
        v.push_back(x);
    for(int x=0;x<v.size();x++)
    {
        int pom=x;
        while(pom<v.size())
        {
            if(v[x].first==v[pom].first)
                pom++;
            else
                break;
        }
        licz-=f(pom-x);
        x=pom-1;
    }
    cout<<licz;
	return 0;
}