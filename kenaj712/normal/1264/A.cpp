#include<bits/stdc++.h>
using namespace std;
set<int> s;
int licz[1000005];
void czysc()
{
    for(auto x:s)
        licz[-x]=0;
    s.clear();
}
void solve()
{
    int a,c,d;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>c;
        licz[c]++;
        s.insert(-c);
    }
    if(s.size()<3)
    {
        cout<<0<<" "<<0<<" "<<0<<'\n';
        czysc();
        return;
    }
    set<int>::iterator it=s.begin();
    int wyn1=licz[-*it];
    it++;
    int wyn2=licz[-*it];
    it++;
    int wyn3=0;
    while(wyn1+wyn2+wyn3<=a/2 && it!=s.end())
    {
        if(wyn2<=wyn1)
            wyn2+=licz[-*it];
        else
            wyn3+=licz[-*it];
        it++;
    }
    it--;
    if(wyn3!=0)
        wyn3-=licz[-*it];
    if(wyn3==0||wyn1>=wyn2||wyn1>=wyn3)
    {
        cout<<0<<" "<<0<<" "<<0<<'\n';
        czysc();
    }
    else
    {
        cout<<wyn1<<" "<<wyn2<<" "<<wyn3<<'\n';
        czysc();
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