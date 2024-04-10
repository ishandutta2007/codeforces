#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,c,d,last=0,licz=1;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>c>>d;
        if(c>last&&d>last)
        {
            licz+=min(c-last,d-last);
            last=max(min(c,d),max(last,max(c-1,d-1)));
        }
        else
            last=max(last,max(c-1,d-1));
    }
    cout<<licz;
	return 0;
}