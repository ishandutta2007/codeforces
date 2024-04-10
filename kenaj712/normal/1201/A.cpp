#include<bits/stdc++.h>
using namespace std;
int tab[1000005][5];
int f(char a)
{
    return int(a)-65;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    string c;
    for(int x=0;x<a;x++)
    {
        cin>>c;
        for(int y=0;y<b;y++)
            tab[y][f(c[y])]++;
    }
    int maks=0,sum=0;
    int d;
    for(int x=0;x<b;x++)
    {
        cin>>d;
        maks=0;
        for(int y=0;y<5;y++)
            maks=max(maks,tab[x][y]);
        sum+=d*maks;
    }
    cout<<sum;
	return 0;
}