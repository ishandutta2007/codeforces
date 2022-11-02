#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    if(c==0)
    {
        if(a==b)
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    if((b-a)%c==0&&((c>0&&b>=a)||(c<0&&a>=b)))
        cout<<"YES";
    else
        cout<<"NO";
	return 0;
}