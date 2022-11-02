#include<bits/stdc++.h>
using namespace std;
int tab[16]= {8, 9, 1, 13,
3 ,12, 7 ,5,
0, 2 ,4, 11,
6 ,10 ,15, 14};
int out[1005][1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int pom=0;
    int a;
    cin>>a;
    for(int x=0;x<a;x+=4)
        for(int y=0;y<a;y+=4)
        {
            for(int q=x;q<x+4;q++)
                for(int w=y;w<y+4;w++)
                    out[q][w]=tab[4*(q-x)+w-y]+pom;
            pom+=16;
        }

    for(int x=0;x<a;x++)
    {
        for(int y=0;y<a;y++)
            cout<<out[x][y]<<" ";
        cout<<'\n';
    }
	return 0;
}