/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void solve()
{
    long long int n,l,r;
    cin>>n>>l>>r;

    if(l==n*(n-1)+1) { cout<<1<<endl; return; }
    if(l==n*(n-1)) { cout<<n<<" "<<1<<endl; return; }

    long long int d=r-l+1,k=n-1;
    while(1)
    {
        if(l<2*k) break;
        l-=2*k;
        k--;
    }

    long long int val=n-k,par=0,ind=0;

    if(l==0) { cout<<n<<" "; d--; par=1; ind=val+1;}
    else
    {
        l--;
        if(l%2==0) par=1;
        ind=val+1+(l/2);
    }

    while(d--)
    {
        if(val==n) { cout<<1<<" "; break; }
        if(par==1)
        {
            cout<<val<<" ";
            par=0;
        }
        else
        {
            cout<<ind++<<" ";
            if(ind==n+1) { val++; ind=val+1; }
            par=1;
        }
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}