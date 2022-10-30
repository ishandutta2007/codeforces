#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    long long c=0,d,pom;
    while(a--)
    {
        cin>>d;
        pom=c;
        c+=d;
        cout<<c/b-pom/b<<" ";
    }
	return 0;
}