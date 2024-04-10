#include<bits/stdc++.h>
using namespace std;
long long nwd(long long a,long long b)
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
    long long a,b,c,d,e;
    cin>>a>>b>>c>>d;
    e=nwd(c,d);
    c/=e;
    d/=e;
    cout<<min(a/c,b/d);
	return 0;
}