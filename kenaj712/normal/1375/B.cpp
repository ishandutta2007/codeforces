#include<bits/stdc++.h>
using namespace std;
int tab[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        bool czy=false;
        for(int x=0;x<a;x++)
            for(int y=0;y<b;y++)
        {
            cin>>tab[x][y];
            int licz=4;
            if(x==0)
                licz--;
            if(x==a-1)
                licz--;
            if(y==0)
                licz--;
            if(y==b-1)
                licz--;
            if(tab[x][y]>licz)
                czy=true;
            tab[x][y]=licz;
        }
        if(czy)
            cout<<"NO"<<'\n';
        else
        {
            cout<<"YES"<<'\n';
            for(int x=0;x<a;x++)
            {
                for(int y=0;y<b;y++)
                    cout<<tab[x][y]<<" ";
                cout<<'\n';
            }
        }
    }
	return 0;
}