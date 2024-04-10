#include<bits/stdc++.h>
using namespace std;
int tab1[505][505];
int tab2[505][505];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            cin>>tab1[x][y];
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            cin>>tab2[x][y];
    for(int x=0;x<a-1;x++)
        for(int y=0;y<b-1;y++)
            if(tab1[x][y]!=tab2[x][y])
            {
                tab1[x][y]=1^tab1[x][y];
                tab1[x+1][y]=1^tab1[x+1][y];
                tab1[x][y+1]=1^tab1[x][y+1];
                tab1[x+1][y+1]=1^tab1[x+1][y+1];
            }
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            if(tab2[x][y]!=tab1[x][y])
            {
                cout<<"No";
                return 0;

            }
    cout<<"Yes";
	return 0;
}