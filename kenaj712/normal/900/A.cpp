#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c;
	int licz=0;
	cin>>a;
	for(int x=0;x<a;x++)
    {
        cin>>b>>c;
        if(b<0)
            licz++;
    }
    if(licz==0||licz==1||licz==a-1||licz==a)
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}