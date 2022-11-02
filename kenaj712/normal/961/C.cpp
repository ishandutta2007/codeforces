#include<bits/stdc++.h>
using namespace std;
int tab[4][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,licz=0;
    char b;
    cin>>a;
    for(int k=0;k<4;k++)
        for(int x=0;x<a;x++)
        {
            licz=0;
            for(int y=0;y<a;y++)
            {
                cin>>b;
                tab[k][(x+y)%2]+=int(b)-48;
            }
        }
    int mini=4*a*a,pom=a*a/2,pom1,pom2;
    for(int x=0;x<4;x++)
        for(int y=x+1;y<4;y++)
        {
            for(int z=0;z<4;z++)
                if(z!=x&&z!=y)
                    pom1=z;
            pom2=6-x-y-pom1;
            mini=min(mini,2*pom+2-tab[x][0]-tab[y][0]+tab[x][1]+tab[y][1]+tab[pom1][0]+tab[pom2][0]+2*pom-tab[pom1][1]-tab[pom2][1]);
            mini=min(mini,4*a*a-(2*pom+2-tab[x][0]-tab[y][0]+tab[x][1]+tab[y][1]+tab[pom1][0]+tab[pom2][0]+2*pom-tab[pom1][1]-tab[pom2][1]));
        }

    cout<<mini;
	return 0;
}