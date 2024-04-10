#include<bits/stdc++.h>
using namespace std;
int licz[4];
int tab[1000005];
int last;
void solve()
{
    int a,b;
        cin>>a>>b;
    last=a;
        for(int x=0;x<=3;x++)
            licz[x]=0;
        for(int x=2;x<=a+1;x++)
        {
            int c,pom;
            cin>>c;
            if(c<b)
                pom=1;
            else if(c==b)
                pom=2;
            else
                pom=3;
            licz[pom]++;
            tab[x]=pom;
        }
    if(a==1 && licz[2]>0)
    {
        cout<<"yes"<<'\n';
        return;
    }
        for(int x=2;x<=a;x++)
            if(tab[x]==2 && tab[x+1]==2)
            {
                cout<<"yes"<<'\n';
                return;
            }
        for(int x=2;x<=a;x++)
            if(tab[x]==2 && tab[x+2]==2)
            {
                cout<<"yes"<<'\n';
                return;
            }
        for(int x=2;x<=a;x++)
            if(tab[x]==2 && tab[x+1]==3)
            {
                cout<<"yes"<<'\n';
                return;
            }
        for(int x=2;x<=a;x++)
            if(tab[x]==3 && tab[x+1]==2)
            {
                cout<<"yes"<<'\n';
                return;
            }
        for(int x=2;x<=a;x++)
            if(tab[x]==2 && tab[x+2]==3)
            {
                cout<<"yes"<<'\n';
                return;
            }
        for(int x=2;x<=a;x++)
            if(tab[x]==3 && tab[x+2]==2)
            {
                cout<<"yes"<<'\n';
                return;
            }
        for(int x=2;x<=a;x++)
            if(tab[x]==3 && tab[x+1]==3 && licz[2]>0)
            {
                cout<<"yes"<<'\n';
                return;
            }
        for(int x=2;x<=a;x++)
            if(tab[x]==3 && tab[x+2]==3 && licz[2]>0)
            {
                cout<<"yes"<<'\n';
                return;
            }
        cout<<"no"<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
    {
        solve();
        for(int x=0;x<=last+3;x++)
            tab[x]=0;
    }

    return 0;
}