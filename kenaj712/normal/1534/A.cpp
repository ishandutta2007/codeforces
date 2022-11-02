#include<bits/stdc++.h>
using namespace std;
char tab[105][105];
int s[2];
char t[2];
void czysc()
{
    for(int x=0;x<2;x++)
    {
        s[x] = 0;
        t[x] = 'e';
    }
}
void solve()
{
    czysc();
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
        {
            cin>>tab[x][y];
            if(tab[x][y]!= '.')
                t[(x+y)%2] = tab[x][y];
            if(tab[x][y] == 'R')
                s[(x+y)%2] |= 1;
            if(tab[x][y] == 'W')
                s[(x+y)%2] |= 2;
        }
    if(s[0] == 3 || s[1] == 3 || (s[0] == s[1] && s[0] != 0))
        cout<<"NO"<<'\n';
    else
    {
        if(t[0] == 'e' && t[1] == 'e')
            t[1] = 'R';
        if(t[1] == 'R')
            t[0] = 'W';
        if(t[1] == 'W')
            t[0] = 'R';
        if(t[0] == 'R')
            t[1] = 'W';
        if(t[0] == 'W')
            t[1] = 'R';
        cout<<"YES\n";
        for(int x=0;x<a;x++)
        {
            for(int y=0;y<b;y++)
                cout<<t[(x+y)%2];
            cout<<'\n';
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