#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,pom=0;
    cin>>a>>b>>c;
    if(a!=b)
        pom++;
    cout<<2*c+2*min(a,b)+pom;
	return 0;
}