#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    int pom;
    for(int x=1;x<=a/2;x++)
    {
        pom=a-x+1;
        for(int y=1;y<=2*b;y++)
        {
            if(y%2==1)
                cout<<x<<" "<<y/2+1<<'\n';
            else
                cout<<pom<<" "<<b-y/2+1<<'\n';
        }
    }
    if(a%2==1)
    {
        pom=a/2+1;
        for(int x=1;x<=b;x++)
        {
            if(x%2==1)
                cout<<pom<<" "<<x/2+1<<'\n';
            else
                cout<<pom<<" "<<b-x/2+1<<'\n';
        }
    }
	return 0;
}