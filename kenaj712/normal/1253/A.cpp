#include<bits/stdc++.h>
using namespace std;
int tab1[1000005];
int tab2[1000005];
int tab3[1000005];
set<int> s;
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab1[x];
    for(int x=0;x<a;x++)
        cin>>tab2[x];
    for(int x=0;x<a;x++)
        tab3[x]=tab1[x]-tab2[x];
    int pocz=0,kon=a-1;
    while(pocz<a)
    {
        if(tab3[pocz]==0)
            pocz++;
        else
            break;
    }
    while(kon>0)
    {
        if(tab3[kon]==0)
            kon--;
        else
            break;
    }
    if(pocz==a)
    {
        cout<<"YES";
        return;
    }
   // cout<<pocz<<" "<<kon<<'\n';
    for(int x=pocz;x<=kon;x++)
        s.insert(tab3[x]);
    if(s.size()==1)
    {
        if(*s.begin()<0)
            cout<<"YES";
        else
            cout<<"NO";
    }
    else
        cout<<"NO";

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
        cout<<'\n';
        s.clear();
    }

	return 0;
}