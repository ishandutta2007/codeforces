#include<iostream>
using namespace std;
int t(int x,int y)
{
	if(x%y>0)
		return x/y+1;
	return x/y;
}
int main()
{
	int q,a,b,c,d,k,t1,t2;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>a>>b>>c>>d>>k;
		t1=t(a,c);
		t2=t(b,d);
		if(t1+t2>k)
			cout<<-1<<endl;
		else
			cout<<t1<<" "<<t2 << endl;
	}
		
}