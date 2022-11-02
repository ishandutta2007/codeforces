#include<bits/stdc++.h>
using namespace std;
string tab[1000005];
int pref[1000005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
    {
        string d;
        cin>>d;
        tab[x] = "." + d;
    }
    tab[0] = "";
    for(int x=1;x<=b;x++)
        tab[0] += ".";
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        {
            if(tab[x-1][y] == 'X' && tab[x][y-1] == 'X')
            {
                //tab[x][y] = 'X';
                pref[y] = 1;
            }
        }
    for(int x=1;x<=b;x++)
        pref[x] = pref[x-1] + pref[x];
    int t;
    cin>>t;
    while(t--)
    {
        int c,d;
        cin>>c>>d;
        if(pref[d] - pref[c])
            cout<<"NO";
        else
            cout<<"YES";
        cout<<'\n';
    }

	return 0;
}