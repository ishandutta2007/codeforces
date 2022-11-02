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
        long long a,b,c;
        cin>>a>>b>>c;
        int licz=0;
        if(a>b)
            swap(a,b);
        while(b<=c)
        {
            a+=b;
            if(a>=b)
                swap(a,b);
            licz++;
        }
        cout<<licz<<'\n';
    }

	return 0;
}