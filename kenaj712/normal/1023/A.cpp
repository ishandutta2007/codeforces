#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    string c,d;
    cin>>c>>d;
    if(a-1>b)
    {
        cout<<"NO";
        return 0;
    }

    bool czy=false;
    for(int x=0;x<a;x++)
    {
        if(c[x]=='*')
            czy=true;
    }
    if(czy==false)
    {
        if(c!=d)
            cout<<"NO";
        else
            cout<<"YES";
    }
    else
    {
        bool czy2=false;
        for(int x=0;x<a;x++)
        {
            if(c[x]=='*')
                break;
            if(c[x]!=d[x])
                czy2=true;
        }
        for(int x=1;x<=a;x++)
        {
            if(c[a-x]=='*')
                break;
            if(c[a-x]!=d[b-x])
                czy2=true;
        }
        if(czy2==false)
            cout<<"YES";
        else
            cout<<"NO";
    }
	return 0;
}