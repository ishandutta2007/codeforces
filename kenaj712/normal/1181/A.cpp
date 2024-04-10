#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d,e;
    cin>>a>>b>>c;
    d=a/c;
    d+=b/c;
    a%=c;
    b%=c;
    if(a+b>=c)
    {
        e=c-max(a,b);
        d++;
        cout<<d<<" "<<e;
    }
    else
        cout<<d<<" "<<0;
	return 0;
}