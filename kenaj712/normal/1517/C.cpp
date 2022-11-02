#include<bits/stdc++.h>
using namespace std;
int tab[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x][x];
    for(int x=1;x<=a;x++)
    {
        int i = x, j = x;
        int pom = tab[x][x], t = tab[x][x];
        while(t--)
        {
            tab[i][j] = pom;
            if(j > 1 && tab[i][j-1] == 0)
                j--;
            else
                i++;
        }
    }
    for(int x=1;x<=a;x++)
    {
        for(int y=1;y<=x;y++)
            cout<<tab[x][y]<<" ";
        cout<<'\n';
    }
	return 0;
}