#include <iostream>

using namespace std;

int main()
{
    long n,l,b=1,c[10001];
    int k;
    cin>>n>>k;
    c[1]=n;
    c[2]=n;
    for(int i=1;i<=k;i++)
    {
		l=n-1;
		if(b>n-2)
		{
	//		if(f==0)
	//		{
	//			f=1;
				for(int r=1;r<=n;r++)
					c[r]=n;
	//		}
		}
		else
		{
			for(int r=1;r<b+2;r++)
				c[r]=n;
			for(int r=b+2;r<=n;r++)
			{
				c[r]=l;
				l--;
			}
		}
		for(int r=n;r>0;r--)
			cout<<c[r]<<" ";
		cout<<endl;
		b=b*2;
    }
}