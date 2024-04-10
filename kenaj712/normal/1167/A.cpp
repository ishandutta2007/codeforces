#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t,a;
    string b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int licz=-1e9;
        for(int x=0;x<a;x++)
        {
            if(b[x]=='8'&&licz<0)
                licz=0;
            licz++;
        }
        if(licz>=11)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
	return 0;
}