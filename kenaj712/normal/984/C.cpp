#include<bits/stdc++.h>
using namespace std;
long long gcd (long long a,long long b)
{
    while(a!=0&&b!=0)
    {
        if(a>b)
        a%=b;
    else
        b%=a;
    }

    if(a==0)
        return b;
    return a;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    long long p,q,b,pom;
    for(int x=0;x<a;x++)
    {
        cin>>p>>q>>b;
        if(p==0)
            cout<<"Finite"<<'\n';
        else
        {
            q/=gcd(p,q);
            pom=gcd(q,b);
            while(pom!=1)
            {
                q/=pom;
                if(q==1)
                    break;
                if(q%pom!=0)
                    pom=gcd(q,b);
            }
            if(q==1)
                cout<<"Finite"<<'\n';
            else
                cout<<"Infinite"<<'\n';
        }
    }
	return 0;
}