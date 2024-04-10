/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    long long int n,k,l1,r1,l2,r2;
    cin>>n>>k>>l1>>r1>>l2>>r2;

    if(r1>r2) { swap(r1,r2); swap(l1,l2); }
    if(r1<l2)
    {
        long long int x=(r2-l2)+(r1-l1);
        long long int y=l2-r1;
        long long int z=(x+y);
        if(k<=z) { cout<<y+k<<endl; return;}
        if(k>n*z) { cout<<n*(z+y)+2*(k-(n*z))<<endl; return;}
        long long int w=(k/z);
        k-=w*z;
        if(k<y) { cout<<w*(z+y)+2*k<<endl; return;}
        else { cout<<w*(z+y)+(k+y)<<endl; return;}
    }
    else if(l1<l2)
    {
        long long int x=n*(r1-l2);
        long long int y=r2-r1+l2-l1;
        if(k<=x) { cout<<0<<endl; return;}
        k-=x;
        if(k<=y*n) { cout<<k<<endl; return;}
        else { cout<<2*k-y*n<<endl; return;}
    }
    else
    {
        long long int x=n*(r1-l1);
        long long int y=r2-r1+l1-l2;
        if(k<=x) { cout<<0<<endl; return;}
        k-=x;
        if(k<=y*n) { cout<<k<<endl; return;}
        else { cout<<2*k-y*n<<endl; return;}
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}