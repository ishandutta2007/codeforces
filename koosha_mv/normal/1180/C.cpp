#include<iostream>
using namespace std;
int main()
{	long long n,q,h;
	cin>>n>>q;
	int hi[n],ref[n],v[n];
	for(int i=0;i<n;i++)
	cin>>v[i];
	hi[0]=v[0];
	for(int i=1;i<n;i++)
	{	hi[i]=max(v[i],hi[i-1]);
		if(hi[i]==v[i])
		ref[i-1]=hi[i-1];
		else
    	ref[i-1]=v[i];
     	}
	while(q--)
	{	cin>>h;
		if(h<n)
			cout<<hi[h-1]<<" "<<v[h]<<endl;
		else
			cout<<hi[n-1]<<" "<<ref[(h-1)%(n-1)]<<endl;
	}
}