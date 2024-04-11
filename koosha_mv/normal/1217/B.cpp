#include<iostream>
using namespace std;
int gerd(float x)
{
	if(x==int(x))
		return x;
	return int(x)+1;
}
int t(int bb,int be,int x)
{
	if(be<=0)
	{
		if(bb>=x)
			return 1;
		return -1;
	}
	if(bb>=x)
		return 1;
	float o=0;
	o=gerd((float(x)-float(bb))/float(be));
	return o+1;
}
int main()
{
	int gg,n,x,bb,be,t1,t2;
	cin>>gg;
	for(int i=0;i<gg;i++)
	{
		 cin>>n>>x;
		 be=0;bb=0;
		 for(int j=0;j<n;j++)
		 {
		 	cin>>t1>>t2;
		 	if(t1-t2>be)
		 		be=t1-t2;
			if(t1>bb)
				bb=t1;
		 }
		 cout<<t(bb,be,x)<<endl;
	}
}