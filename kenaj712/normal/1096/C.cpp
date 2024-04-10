#include<bits/stdc++.h>
using namespace std;
int tab[200];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int x=1;x<180;x++)
    {
        for(int y=3;y<10000;y++)
        {
            if((x*y)%180==0&&180*(y-2)>=x*y)
            {
                tab[x]=y;
                break;
            }
        }
    }
    int t,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        if(tab[a]!=0)
            cout<<tab[a]<<'\n';
        else
            cout<<-1<<'\n';
    }
	return 0;
}