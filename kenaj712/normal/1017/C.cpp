#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int pom=sqrt(a);
    for(int x=a-pom+1;x>-pom;x-=pom)
    {
        for(int y=max(1,x);y<x+pom;y++)
            cout<<y<<" ";
    }

	return 0;
}