#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        string d;
        cin>>a>>d;
        bool czy=false;
        for(int x=0;x<a/2;x++)
        {
            if(int(d[x])-int(d[a-x-1])!=0&&abs(int(d[x])-int(d[a-x-1]))!=2)
                czy=true;
        }
        if(czy==true)
            cout<<"NO"<<'\n';
        else
            cout<<"YES"<<'\n';
    }
	return 0;
}