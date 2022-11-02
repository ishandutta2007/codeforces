#include<bits/stdc++.h>
using namespace std;
int licz=0;
string tab[105];
vector<int> liczby;
bool pol[45][45];
int maska1[45];
int maska2[45];
int dp1[2000005];
int dp2[2000005];
vector<int> maski1[105];
vector<int> maski2[105];
int cnt(int a)
{
    int licz=0;
    while(a!=0)
    {
        licz+=a%2;
        a/=2;
    }
    return licz;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,pom;
    string slowo;
    cin>>a>>b;
    while(a--)
    {
        cin>>c;
        if(c==1)
        {
            for(auto x:liczby)
                for(auto y:liczby)
                    pol[x][y]=true;
            liczby.resize(0);
        }
        else
        {
            cin>>slowo;
            pom=0;
            for(int x=1;x<=licz;x++)
                if(tab[x]==slowo)
                    pom=x;
            if(pom!=0)
                liczby.push_back(pom);
            if(pom==0)
            {
                liczby.push_back(licz+1);
                licz++;
                tab[licz]=slowo;
            }
        }
    }
    for(auto x:liczby)
        for(auto y:liczby)
            pol[x][y]=true;
    liczby.resize(0);
    for(int x=1;x<=b;x++)
        for(int y=1;y<=b;y++)
        {
            if(x!=y)
            {
                if(pol[x][y]==true)
                    pol[x][y]=false;
                else
                    pol[x][y]=true;
            }
        }
    int ile=b/2;
    for(int x=1;x<=b;x++)
    {
        pom=0;
        for(int y=1;y<=ile;y++)
        {
            pom*=2;
            pom+=pol[x][y];
        }
        maska1[x]=pom;
        pom=0;
        for(int y=ile+1;y<=b;y++)
        {
            pom*=2;
            pom+=pol[x][y];
        }
        maska2[x]=pom;
    }
    //for(int x=1;x<=b;x++)
        //cout<<x<<" : "<<maska1[x]<<" "<<maska2[x]<<'\n';
    for(int x=0;x<(1<<ile);x++)
        maski1[cnt(x)].push_back(x);
    for(int x=0;x<(1<<(b-ile));x++)
        maski2[cnt(x)].push_back(x);
    bool czy;
    for(int x=0;x<ile;x++)
    {
        for(auto y:maski1[x])
        {
            pom=ile;
            for(int z=1;z<(1<<ile);z*=2)
            {
                if((y&z)==0)
                {
                    if((y&maska1[pom])==y)
                        dp1[y+z]=max(dp1[y+z],dp1[y]+1);
                    else
                        dp1[y+z]=max(dp1[y+z],dp1[y]);
                }
                pom--;
            }
        }

    }
    for(int x=0;x<b-ile;x++)
    {
        for(auto y:maski2[x])
        {
            pom=b;
            for(int z=1;z<(1<<(b-ile));z*=2)
            {
                if((y&z)==0)
                {
                    //cout<<"XD "<<y<<" "<<pom<<" "<<maska2[pom]<<'\n';
                    if((y&maska2[pom])==y)
                        dp2[y+z]=max(dp2[y+z],dp2[y]+1);
                    else
                        dp2[y+z]=max(dp2[y+z],dp2[y]);
                }
                pom--;
            }
        }
    }
   // for(int x=0;x<=7;x++)
       // cout<<x<<" : "<<dp2[x]<<'\n';
    int maks=0,pom2;
    for(int x=0;x<(1<<ile);x++)
    {
        pom=(1<<(b-ile))-1;
        pom2=x;
        for(int y=ile;y>0;y--)
        {
            if(pom2%2==1)
                pom&=maska2[y];
            pom2/=2;
        }
        maks=max(maks,dp1[x]+dp2[pom]);
    }
    cout<<maks;
	return 0;
}