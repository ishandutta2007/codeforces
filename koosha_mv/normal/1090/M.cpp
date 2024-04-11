#include<iostream>
using namespace std;
int minn(int x,int y)
{
	if(x<y)
	 return x;
	return y;
}
int maxx(int x,int y)
{
	if(x>y)
	 return x;
	return y;
}
int main()
{
	int n,k2,t2=-1;
	cin >> n >> k2;
	int kh[100000];
	for(int i=0;i<n;i++)
		cin >> kh[i];
	if(n==1)
	{
		cout << 1;
		return 0;
	}
	int k=0,b=0,ch=1,t=0,j;
	for(int i=0;i<n-1;i++)
	{
		t=ch-i;
		j=ch;
		int s=0;
		while(kh[j]!=kh[j-1] && j<=n)
		{
			s++;
			t++;
			j++;
		}
		ch=maxx(j,i+2);
		if(t>t2)
		{
			t2=t;
			b=j;
			k=i;
		}  
	}
	if(b>n)
		cout << n-k;
	else
		cout << b-k;
}