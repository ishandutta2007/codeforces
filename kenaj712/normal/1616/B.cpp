#include<bits/stdc++.h>
using namespace std;
int tab[10005];
void solve()
{
    int d;
    cin>>d;
    string a;
    cin>>a;
    char mini = 'z';
    for(auto x:a)
        mini = min(mini, x);
    if(d == 1)
    {
        cout<<a<<a<<'\n';
        return;
    }
    if(a[0] <= a[1])
    {
        cout<<a[0]<<a[0]<<'\n';
        return;
    }

    for(int x=0;x<a.size();x++)
    {
        if(x == a.size() - 1)
        {
            cout<<a;
            reverse(a.begin(),a.end());
            cout<<a<<'\n';
            return;
        }
        if(a[x] < a[x+1])
        {
            for(int y=0;y<=x;y++)
                cout<<a[y];
            for(int y=x;y>=0;y--)
                cout<<a[y];
            cout<<'\n';
            return;
        }
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