#include<bits/stdc++.h>
using namespace std;
vector<int> v1[10005];
vector<int> v2[10005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
    {
        cin>>c;
        v1[x+y].push_back(c);
    }
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
    {
        cin>>c;
        v2[x+y].push_back(c);
    }
    bool czy=true;
    for(int x=0;x<a+b+10;x++)
    {
        sort(v1[x].begin(),v1[x].end());
        sort(v2[x].begin(),v2[x].end());
        if(v1[x]!=v2[x])
            czy=false;
    }
    if(czy==true)
        cout<<"YES";
    else
        cout<<"NO";

	return 0;
}