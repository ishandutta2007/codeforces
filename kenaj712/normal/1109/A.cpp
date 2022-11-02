#include<bits/stdc++.h>
using namespace std;
long long v[2000005][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    v[0][0]++;
    int a,c,act=0;
    cin>>a;
    for(int x=1;x<=a;x++)
    {
        cin>>c;
        act^=c;
        v[act][x%2]++;
    }
    long long licz=0;
    for(int x=0;x<=2000000;x++)
        licz+=v[x][0]*(v[x][0]-1)/2+v[x][1]*(v[x][1]-1)/2;
    cout<<licz;
	return 0;
}