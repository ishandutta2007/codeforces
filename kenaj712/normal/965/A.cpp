#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long pom1;
    if(b%c==0)
        pom1=b/c;
    else
        pom1=b/c+1;
    pom1*=a;
    if(pom1%d==0)
        cout<<pom1/d;
    else
        cout<<pom1/d+1;

	return 0;
}