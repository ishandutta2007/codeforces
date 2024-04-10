#include<bits/stdc++.h>
using namespace std;
int dziel[1000005];
void sito()
{
    for(int x=2;x<=1e6;x++)
    {
        if(dziel[x]==0)
            for(int y=x;y<=1e6;y+=x)
                dziel[y]=x;
    }
}
set<int> s;
int maks[1000005];
int licz[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    sito();
    int a,b,c;
    cin>>a>>b;
    while(a--)
    {
        cin>>c;
        while(c!=1)
        {
            licz[dziel[c]]++;
            s.insert(dziel[c]);
            c/=dziel[c];
        }
        for(auto x:s)
        {
            maks[x]=max(maks[x],licz[x]);
            licz[x]=0;
        }
        s.clear();
    }
    c=b;
    while(c!=1)
    {
        licz[dziel[c]]++;
        s.insert(dziel[c]);
        c/=dziel[c];
    }
    for(auto x:s)
    {
        if(maks[x]<licz[x])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
	return 0;
}