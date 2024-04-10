#include<bits/stdc++.h>
using namespace std;
long long tab[1000005][3];
bool block[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        for(int y=0;y<3;y++)
            cin>>tab[x][y];
    for(int x=1;x<=a;x++)
    {
        if(block[x]==false)
        {
            pair<long long,int> p=make_pair(1e18,0);
            for(int y=x+1;y<=a;y++)
                if(block[y]==false)
                    p=min(p,make_pair(abs(tab[y][0]-tab[x][0])+abs(tab[y][1]-tab[x][1])+abs(tab[y][2]-tab[x][2]),y));
            cout<<x<<" "<<p.second<<'\n';
            block[p.second]=true;
        }
    }
	return 0;
}