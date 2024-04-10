#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,k;
    cin>>a>>b>>k;
    if(k<a)
        cout<<k+1<<" "<<1;
    else
    {
        b--;
        k-=a;
        if((k/b)%2==0)
            cout<<a-k/b<<" "<<2+k%b;
        else
            cout<<a-k/b<<" "<<b+1-k%b;
    }
	return 0;
}