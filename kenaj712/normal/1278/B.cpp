#include<bits/stdc++.h>
using namespace std;
bool check(long long a,long long b)
{
    if(a==0)
        return true;
    if(b>=3)
        return true;
    else
        return false;
}
void solve()
{
    long long a,b,c;
    cin>>a>>b;
    a=abs(a-b);
    for(long long x=0;x<=1e6;x++)
    {
        c=x*(x+1)/2-a;
        if(c%2==1 || c<0)
            continue;
        /*c/=2;
        long long d=x*(x+1)/2-c;
        if(c>=0&&check(c,x))
        {*/
            cout<<x<<'\n';
            return ;
        //}

    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}