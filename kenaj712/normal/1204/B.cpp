#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d,e,sum1=0,sum2=0;
    cin>>a>>b>>c;
    d=a;
    e=1;
    while(d--)
    {
        sum1+=e;
        b--;
        if(b>0)
            e*=2;
        else
            e=1;
    }
    d=a;
    e=1;
    while(d--)
    {
        sum2+=e;
        c--;
        if(c>0)
            e*=2;
    }
    cout<<sum1<<" "<<sum2;
	return 0;
}