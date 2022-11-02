#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	cin>>a>>b;
	if(a==1&&b==1)
    {
        cout<<0;
        return 0;
    }
	if(a==1)
    {
        for(int x=2;x<=b+1;x++)
            cout<<x<<" ";
    }
    else if(b==1)
    {
        for(int x=2;x<=a+1;x++)
            cout<<x<<'\n';
    }
    else
    {
        for(int x=1;x<=a;x++)
        {
            for(int y=1;y<=b;y++)
            {
                    cout<<x*(y+a);
                cout<<" ";
            }
            cout<<'\n';
        }
    }
	return 0;
}