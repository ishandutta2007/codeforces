#include<bits/stdc++.h>
using namespace std;
char tab[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin>>a;
	for(int x=1;x<=a;x++)
        for(int y=1;y<=a;y++)
            cin>>tab[x][y];
    int licz=0;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=a;y++)
            if(tab[x][y]=='X'&&tab[x-1][y-1]=='X'&&tab[x-1][y+1]=='X'&&tab[x+1][y-1]=='X'&&tab[x+1][y+1]=='X')
                licz++;
    cout<<licz;
	return 0;
}