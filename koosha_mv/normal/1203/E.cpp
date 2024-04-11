#include<iostream>
using namespace std;
int a[150005]={0};
int a1[150005]={0};
int main()
{
	int n,x,j=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		a[x]++;
	}
	if(a1[1]==0 && a[1]>0)
		{
			j+=1;
			a[1]--;
			a1[1]=1;
		}
		if(a1[2]==0 && a[1]>0)
		{
			j+=1;
			a[1]--;
			a1[2]=1;
		}
	for(int i=2;i<150003;i++)
	{
		if(a1[i-1]==0 && a[i]>0)
		{
			j+=1;
			a[i]--;
		}
		if(a1[i]==0 && a[i]>0)
		{
			j+=1;
			a[i]--;
			a1[i]=1;
		}
		if(a1[i+1]==0 && a[i]>0)
		{
			j+=1;
			a[i]--;
			a1[i+1]=1;
		}
	}
	cout<<j;
}