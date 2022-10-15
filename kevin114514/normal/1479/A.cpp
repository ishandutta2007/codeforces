#include<bits/stdc++.h>
using namespace std;
int query(int x)
{
	cout<<"? "<<x<<endl;
	int ret;
	cin>>ret;
	cout.flush();
	return ret;
}
void found(int x)
{
	cout<<"! "<<x<<endl;
	exit(0);
}
int main()
{
	int n;
	cin>>n;
	int l=1,r=n;
	int lv=query(1),rv=query(n);
	if(lv==1)
		found(1);
	if(rv==1)
		found(n);
	while(r-l>=2)
	{
		int mid=(l+r)/2;
		int midv=query(mid);
		int midlv=query(mid-1);
		int midrv=query(mid+1);
		if(midv>midrv)
			l=mid+1;
		else if(midv>midlv)
			r=mid-1;
		else	found(mid);
	}
	if(r-l==1)
	{
		if(query(l)<query(r))
			found(l);
		else	found(r);
	}
	if(r==l)
		found(l);
	return 0;
}