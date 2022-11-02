#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a;
    cin>>a;
    if(a%2==1)
        cout<<0;
    else
    {
        long long pom=1,pom1=a/2;
        while(pom1--)
            pom*=2;
        cout<<pom;
    }
	return 0;
}