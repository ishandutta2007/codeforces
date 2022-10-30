#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,maks=1000000001;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>b>>c;
        if(b>maks&&c>maks)
        {
            cout<<"NO";
            return 0;
        }
        if(b>maks)
            maks=c;
        else if(c>maks)
            maks=b;
        else
            maks=max(b,c);
    }
    cout<<"YES";
	return 0;
}