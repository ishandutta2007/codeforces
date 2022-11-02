#include<bits/stdc++.h>
using namespace std;
set<long long> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b;
    cin>>a;
    b=a;
    for(long long x=2;x<=1e6;x++)
    {
        while(a%x==0)
        {
            s.insert(x);
            a/=x;
        }
    }
    if(a!=1)
        s.insert(a);
    if(s.size()>1)
        cout<<1;
    else if(s.size()==0)
        cout<<b;
    else
        cout<<(*s.begin());
	return 0;
}