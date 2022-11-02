#include<bits/stdc++.h>
using namespace std;
vector<int> v;
char f(char a)
{
    if(a=='1')
        return '0';
    else
        return '1';
}
void solve()
{
    int xd;
    cin>>xd;
    string a,b;
    cin>>a>>b;
    for(int x=a.size()-1;x>=1;x--)
    {
        if(a[x]!=b[x])
        {
            if(a[x]!=a[0])
            {
                v.push_back(1);
                a[0]=f(a[0]);
            }
            v.push_back(x+1);
            for(int y=0;y<=x/2;y++)
                if(a[y]==a[x-y])
                {
                    a[y]=f(a[y]);
                    if(y!=x-y)
                        a[x-y]=f(a[x-y]);
                }
        }
    }
    if(a[0]!=b[0])
        v.push_back(1);
    cout<<v.size()<<" ";
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