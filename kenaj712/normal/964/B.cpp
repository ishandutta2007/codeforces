#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n,a,b,c,t;
    cin>>n>>a>>b>>c>>t;
    if(b>=c)
        cout<<a*n;
    else
    {
        int pom,pom2=a*n;
        for(int x=0;x<n;x++)
        {
            cin>>pom;
            pom2+=(t-pom)*(c-b);
        }
        cout<<pom2;
    }

	return 0;
}