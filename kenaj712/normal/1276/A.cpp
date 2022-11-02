#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void solve()
{
    string a;
    cin>>a;
    for(int x=0;x<a.size();x++)
    {
        if(x+4<a.size())
        {
            if(a[x]=='t' && a[x+1]=='w' && a[x+2]=='o' && a[x+3]=='n' && a[x+4]=='e')
            {
                v.push_back(x+3);
                x+=4;
                continue;
            }
        }
        if(x+2<a.size())
        {
            if(a[x]=='t' && a[x+1]=='w' && a[x+2]=='o')
            {
                v.push_back(x+2);
                x+=1;
                continue;
            }
        }
        if(x+2<a.size())
        {
            if(a[x]=='o' && a[x+1]=='n' && a[x+2]=='e')
            {
                v.push_back(x+2);
                x+=1;
                continue;
            }
        }
    }
    cout<<v.size()<<'\n';
    for(auto x:v)
        cout<<x<<" ";
    cout<<'\n';
    v.resize(0);
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