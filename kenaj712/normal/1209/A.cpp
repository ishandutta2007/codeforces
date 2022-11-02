#include<bits/stdc++.h>
using namespace std;
bool tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        tab[b]=true;
    }
    int licz=0;
    for(int x=1;x<=100;x++)
    {
        if(tab[x]==true)
        {
            licz++;
            for(int y=x;y<=100;y+=x)
                tab[y]=false;
        }
    }
    cout<<licz;
	return 0;
}