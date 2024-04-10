#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,x,y;
    int t;
    cin>>a>>t;
    while(t--)
    {
        cin>>x>>y;
        if(a%2==0)
        {
            if((x+y)%2==0)
            {
                x--;
                cout<<a*x/2+(y+1)/2<<'\n';
            }
            else
            {
                x--;
                cout<<a*a/2+a*x/2+(y+1)/2<<'\n';
            }
        }
        else
        {
            if((x+y)%2==0)
            {
                if(x%2==1)
                    cout<<a*((x-1)/2)+(y+1)/2<<'\n';
                else
                    cout<<a*((x-1)/2)+a/2+1+(y+1)/2<<'\n';
            }
            else
            {
                if(x%2==1)
                    cout<<a*a/2+1+a*(x-1)/2+(y+1)/2<<'\n';
                else
                    cout<<a*a/2+1+a/2+1+a*((x-1)/2)+y/2<<'\n';
            }
        }
    }
	return 0;
}