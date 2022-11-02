#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	long long cost=0;
	if(b==1)
    {
        cout<<(a-1)*c;
        return 0;
    }
	while(a!=1)
    {
        if(a==0)
        {
            cost-=c;
            break;
        }
        if(a%b!=0)
        {
            cost+=(a%b)*c;
            a-=a%b;
        }
        else if((a-a/b)*c<d)
        {
            cost+=(a-a/b)*c;
            a/=b;
        }
        else
        {
            cost+=d;
            a/=b;
        }
    }
    cout<<cost;
	return 0;
}