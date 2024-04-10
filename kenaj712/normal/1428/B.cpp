#include<bits/stdc++.h>
using namespace std;
int licz[2];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int d;
        cin>>d;
        string a;
        cin>>a;
        bool czy1=false,czy2=false;
        for(auto x:a)
        {
            if(x=='<')
                czy1=true;
            if(x=='>')
                czy2=true;
        }
        int licz=0;
        if(czy1&czy2)
        {
            for(int x=0;x<d;x++)
                if(a[x]=='-' || a[(x+1)%d]=='-')
                    licz++;
        }
        else
            licz=d;
        cout<<licz<<'\n';
    }
	return 0;
}