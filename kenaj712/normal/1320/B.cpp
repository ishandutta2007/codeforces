#include<bits/stdc++.h>
using namespace std;
vector<int> pol[1000005];
vector<int> odwr[1000005];
bool odw[1000005];
int odl[1000005];
int tab[1000005];
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d;
	cin>>a>>b;
	while(b--)
    {
        cin>>c>>d;
        pol[d].push_back(c);
        odwr[c].push_back(d);
    }
    cin>>c;
    for(int x=1;x<=c;x++)
        cin>>tab[x];
    odw[tab[c]]=true;
    q.push(tab[c]);
    while(q.empty()==false)
    {
        int pom=q.front();
        q.pop();
        for(auto x:pol[pom])
            if(odw[x]==false)
            {
                odl[x]=odl[pom]+1;
                odw[x]=true;
                q.push(x);
            }
    }
    int mini=0,maks=0;
    for(int x=1;x<c;x++)
    {
        int mniej=0,row=0;
        for(auto y:odwr[tab[x]])
        {
            if(odl[y]==odl[tab[x+1]])
                row++;
            else if(odl[y]<odl[tab[x+1]])
                mniej++;
        }
        if(mniej!=0)
        {
            mini++;
            maks++;
        }
        else if(row>1)
            maks++;
    }
    cout<<mini<<" "<<maks;
	return 0;
}