#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    string b;
    cin>>a>>b;
    int mini=0,suma=0;
    for(auto x:b)
    {
        if(x=='-')
            suma--;
        else
            suma++;
        mini=min(mini,suma);
    }
    cout<<suma-mini;
	return 0;
}