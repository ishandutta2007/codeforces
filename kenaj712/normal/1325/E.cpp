#include<bits/stdc++.h>
using namespace std;
int dziel[1000005];
vector<int> pol[1000005];
bool spec[1000005];
vector<int> v;
bool odw[1000005];
int odl[1000005];
int zlicz[1000005];
int lul[1000005];
set<int> s;
void sito()
{
    for(int x=2;x<=1000000;x++)
        if(dziel[x]==0)
            for(int y=x;y<=1000000;y+=x)
                if(dziel[y]==0)
                    dziel[y]=x;
}
bool check_square(int a)
{
    int pom=sqrt(a);
    for(int x=pom-100;x<=pom+100;x++)
        if(x*x==a)
            return true;
    return false;
}
int mini=1e9;
queue<int> q;
void kurwa(int a)
{
    q.push(a);
    odw[a]=true;
    v.push_back(a);
    while(q.empty()==false)
    {
        int pom=q.front();
        q.pop();
        for(auto x:pol[pom])
        {
            if(odw[x] && odl[x] == odl[pom])
                mini=min(mini,2*odl[x]+1);
            if(odw[x] && odl[x]==odl[pom]+1)
                mini=min(mini,2*odl[x]);
            if(!odw[x])
            {
                odw[x]=true;
                odl[x]=odl[pom]+1;
                v.push_back(x);
                q.push(x);
            }
        }
    }
    while(!v.empty())
    {
        odl[v.back()]=0;
        odw[v.back()]=false;
        v.pop_back();
    }
    v.resize(0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    sito();
    int a;
    cin>>a;
for(int x=0;x<a;x++)
{
cin>>lul[x];
if(check_square(lul[x]))
        {
            cout<<1;
            return 0;
        }

}
    for(int x=0;x<a;x++)
    {
        int b;
        b=lul[x];
        if(check_square(b))
        {
            cout<<1;
            return 0;
        }
        int licz=0,pom=b;
        while(pom!=1)
        {
            s.insert(dziel[pom]);
            zlicz[dziel[pom]]++;
            pom/=dziel[pom];
            licz++;
        }
        if(licz==2)
        {
            int pom1,pom2;
            pom1=dziel[b];
            b/=dziel[b];
            pom2=b;
            pol[pom1].push_back(pom2);
            pol[pom2].push_back(pom1);
        }
        else
        {
            int xdd=438794854;
            for(auto x:s)
                if(zlicz[x]%2==1)
                    xdd=x;
            for(auto x:s)
                zlicz[x]=0;
            if(spec[xdd])
            {
                cout<<2;
                return 0;
            }
            spec[xdd]=true;
        }
        for(auto x:s)
                zlicz[x]=0;
        s.clear();
    }
    for(int x=1;x<=1000;x++)
        kurwa(x);
    for(int x=1;x<=1000000;x++)
        if(spec[x])
        {
            q.push(x);
            odw[x]=true;
        }
    while(!q.empty())
    {
        int pom=q.front();
        q.pop();
        for(auto x:pol[pom])
        {
            if(!odw[x])
            {
                q.push(x);
                odl[x]=odl[pom]+1;
                odw[x]=true;
            }
            else
            {
                if(odl[x]>=odl[pom])
                    mini=min(mini,odl[x]+odl[pom]+3);
            }
        }
    }
    if(mini==1e9)
        cout<<-1;
    else
        cout<<mini;
    return 0;
}