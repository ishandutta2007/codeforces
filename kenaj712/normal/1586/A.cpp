#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
bool prime(int a)
{
    for(int x=2;x*x<=a;x++)
        if(a%x==0)
            return false;
    return true;
}
void solve()
{
    int a;
    cin>>a;
    int sum = 0;
    int indeks = -1;
    for(int x=1;x<=a;x++)
    {
        cin>>tab[x];
        sum += tab[x];
        if(tab[x] % 2)
            indeks = x;
    }
    if(prime(sum))
    {
        cout<<a-1<<'\n';
        for(int x=1;x<=a;x++)
            if(x != indeks)
                cout<<x<<" ";
        cout<<'\n';
    }
    else
    {
        cout<<a<<'\n';
        for(int x=1;x<=a;x++)
            cout<<x<<" ";
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