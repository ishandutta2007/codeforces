#include<bits/stdc++.h>
using namespace std;
vector<int> out;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    a+=2000;
    out.push_back(-1);
    while(a>1e6)
    {
        a-=1e6;
        out.push_back(1e6);
    }
    cout<<2000<<'\n';
    out.push_back(a);
    for(int x=0;x<2000;x++)
    {
        if(x<out.size())
            cout<<out[x]<<" ";
        else
            cout<<0<<" ";
    }
	return 0;
}