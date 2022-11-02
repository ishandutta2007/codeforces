#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    int xd=a;
    int out=1;
    while(a!=0)
    {
        if(a==3)
        {
            cout<<out<<" "<<out<<" "<<out*3;
            return 0;
        }
        int pom=a/2+a%2;
        a-=pom;
        while(pom--)
            cout<<out<<" ";
        out*=2;
    }

	return 0;
}