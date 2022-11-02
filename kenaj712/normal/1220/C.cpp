#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    char maks='z';
    for(auto x:a)
    {
        if(maks<x)
            cout<<"Ann";
        else
            cout<<"Mike";
        cout<<'\n';
        maks=min(maks,x);

    }
	return 0;
}