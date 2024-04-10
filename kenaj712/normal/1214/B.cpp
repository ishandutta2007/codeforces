#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,ans=0;
    cin>>a>>b>>c;
    for(int x=0;x<=a;x++)
        for(int y=0;y<=b;y++)
        {
            if(x+y==c)
                ans++;
        }
    cout<<ans;

	return 0;
}