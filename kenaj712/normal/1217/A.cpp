#include<bits/stdc++.h>
using namespace std;
long long zero;
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
        a+=c;
        a-=b;
        a++;
        cout<<min(c+1,max(a/2,zero))<<'\n';
    }
	return 0;
}