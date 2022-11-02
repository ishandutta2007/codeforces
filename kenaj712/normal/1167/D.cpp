#include<bits/stdc++.h>
using namespace std;
int licz=0;
int main()
{
	ios_base::sync_with_stdio(0);
	int a;
	string b;
	cin>>a>>b;
	for(auto x:b)
    {
        if(x=='(')
        {
            if(licz%2==0)
                cout<<0;
            else
                cout<<1;
            licz++;
        }
        if(x==')')
        {
            if(licz%2==1)
                cout<<0;
            else
                cout<<1;
            licz--;
        }
    }

	return 0;
}