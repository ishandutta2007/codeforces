#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
set<int> s;
void solve()
{
    int a,b;
    cin>>a>>b;
    b--;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        s.insert(tab[x]);
    }
    bool zero=false;
    if(tab[0]==0)
        zero=true;
    int pom=s.size()-1;
    if(b==0)
    {
        if(zero)
        {
            if(pom>0)
                cout<<-1;
            else
                cout<<0;
        }
        else
        {
            if(pom==0)
                cout<<1;
            else
                cout<<-1;
        }
    }
    else
        cout<<max(1,(pom+b-1)/b);
    cout<<'\n';
    s.clear();
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
}//xd