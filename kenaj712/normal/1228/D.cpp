#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
bool odw[1000005];
int kolor[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d;
    cin>>a>>b;
    while(b--)
    {
        cin>>c>>d;
        pol[c].push_back(d);
        pol[d].push_back(c);
    }
    b=0;
    for(auto x:pol[1])
    {
        odw[x]=true;
        b++;
    }
    kolor[1]=1;
    for(int x=2;x<=a;x++)
        if(odw[x]==false)
        {
            kolor[x]=1;
            if(pol[x].size()!=b)
            {
                cout<<-1;
                return 0;
            }
            for(auto y:pol[x])
                if(odw[y]==false)
                {
                    cout<<-1;
                    return 0;
                }
        }
    c=0;
    for(int x=1;x<=a;x++)
        if(odw[x]==true)
        {
            for(auto y:pol[x])
                if(odw[y]==true)
                {
                    kolor[y]=2;
                    c++;
                }
            break;
        }
    for(int x=1;x<=a;x++)
        if(odw[x]==true&&kolor[x]==0)
        {
            kolor[x]=3;
            if(pol[x].size()!=a+c-b)
            {
                cout<<-1;
                return 0;
            }
            for(auto y:pol[x])
                if(kolor[y]!=2&&kolor[y]!=1)
                {
                    cout<<-1;
                    return 0;
                }
        }
    for(int x=1;x<=a;x++)
        if(kolor[x]==2)
        {
            for(auto y:pol[x])
                if(kolor[y]==2)
                {
                    cout<<-1;
                    return 0;
                }
        }
    set<int> s;
    for(int x=1;x<=a;x++)
        s.insert(kolor[x]);
    if(s.size()<3)
    {
        cout<<-1;
        return 0;
    }
    for(int x=1;x<=a;x++)
        cout<<kolor[x]<<" ";
	return 0;
}