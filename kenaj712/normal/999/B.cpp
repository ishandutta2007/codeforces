#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    string d;
    cin>>d;
    for(int x=2;x<=a;x++)
    {
        if(a%x==0)
        {
            string b="";
            for(int y=x-1;y>=0;y--)
                b+=d[y];
            for(int y=x;y<a;y++)
                b+=d[y];
            d=b;
        }

    }
    cout<<d;
	return 0;
}