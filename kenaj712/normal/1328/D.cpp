#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
bool color[1000005];
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab[x];
    tab[a]=tab[0];
    bool czy=true;
    for(int x=0;x<a;x++)
        if(tab[x]!=tab[x+1])
            czy=false;
    if(czy)
    {
        cout<<1<<'\n';
        while(a--)
            cout<<1<<" ";
        cout<<'\n';
        return ;
    }
    if(a%2==0)
    {
        cout<<2<<'\n';
        while(a--)
            cout<<a%2+1<<" ";
        cout<<'\n';
    }
    else
    {
        czy=false;
        for(int x=1;x<a;x++)
            if(tab[x]==tab[x-1])
            {
                czy=true;
                color[x]=true;
                break;
            }
        if(czy || tab[a-1]==tab[0])
        {
            cout<<2<<'\n';
            int change=0;
            for(int x=0;x<a;x++)
            {
                if(color[x])
                {
                     change++;
                     color[x]=false;
                }

                cout<<(x+change)%2+1<<" ";
            }

        }
        else
        {
            cout<<3<<'\n';
            for(int x=0;x<a-1;x++)
                cout<<x%2+1<<" ";
            cout<<3;
        }
        cout<<'\n';
    }

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}