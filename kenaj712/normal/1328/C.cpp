#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string a;
    int xd;
    cin>>xd>>a;
    bool czy=false;
    string b="",c="";
    for(auto x:a)
    {
        if(!czy)
        {
            if(x=='0')
            {
                b+='0';
                c+='0';
            }
            if(x=='1')
            {
                czy=true;
                b+='1';
                c+='0';
            }
            if(x=='2')
            {
                b+='1';
                c+='1';
            }
        }
        else
        {
            if(x=='0')
            {
                b+='0';
                c+='0';
            }
            if(x=='1')
            {
                b+='0';
                c+='1';
            }
            if(x=='2')
            {
                b+='0';
                c+='2';
            }
        }
    }
    cout<<b<<'\n'<<c<<'\n';
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