#include<bits/stdc++.h>
using namespace std;
long long mst(long long a,long long res,long long b)
{
	long long l=1,r=b;
	while(l<r)
	{
		long long mid=(l+r+1)/2;
		if((mid+1)*res>a)
			r=mid-1;
		else	l=mid;
	}
	return l;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long mxb=sqrt(a+1);
        mxb=min(mxb,b);
        long long ans=mxb*(mxb-1)/2;
        for(long long res=mxb-1;res>0;res--)
        {
        	ans+=res*(mst(a,res,b)-max(mst(a,res+1,b),mxb));
        }
        cout<<ans<<endl;
        //system("pause");
    }
    return 0;
}