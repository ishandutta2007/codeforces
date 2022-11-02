#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d,n;
    cin>>n>>a>>b>>c>>d;
    long long pom=0;
    pom=max(pom,abs(a-d));
    pom=max(pom,abs(b-c));
    pom=max(pom,abs(b+d-a-c));
    pom=max(pom,abs(d+c-a-b));
    pom=n-pom;
    if(pom<=0)
        cout<<0;
    else
        cout<<pom*n;
	return 0;
}