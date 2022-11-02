#include<bits/stdc++.h>
using namespace std;
bool odw[10005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    if(b==0)
    {
        cout<<1;
        return 0;
    }
    for(int x=1;x<=a-1;x++)
        odw[x]=true;
    b--;
    for(int x=1;x<=a;x++)
    {
        if(odw[x-1]==true&&odw[x+1]==true&&odw[x]==true&&b>0)
        {
            odw[x]=false;
            b--;
        }
    }
    for(int x=1;x<=a;x++)
    {
        if((odw[x-1]==true||odw[x+1]==true)&&odw[x]==true&&b>0)
        {
            odw[x]=false;
            b--;
        }
    }
    for(int x=1;x<=a;x++)
    {
        if(odw[x]==true&&b>0)
        {
            odw[x]=false;
            b--;
        }
    }
    int licz=0;
    for(int x=1;x<=a;x++)
        if(odw[x]==true&&odw[x+1]==false)
            licz++;
    cout<<licz;
	return 0;
}