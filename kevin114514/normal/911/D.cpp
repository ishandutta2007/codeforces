#include<bits/stdc++.h>
using namespace std;
int a[1550],n;
bool ans;
void Gets()
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				ans^=1;
	return ;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	Gets();
	int m;
	cin>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		int len=r-l+1;
		if(len%4==2||len%4==3)
			ans^=1;
		if(ans)
			puts("odd");
		else	puts("even");
	}
	return 0;
}