#include<iostream>
#include<algorithm>
using namespace std;
int a[100002];
int m[3][2]={0};
int ezaf(int x)
{
	if(m[0][0]==x)
	{
		m[0][1]++;
		return 0;
	}
	if(m[1][0]==x)
	{
		m[1][1]++;
		return 0;
	}
	m[2][0]=x;
	m[2][1]=1;
}
int menha(int x)
{
	for(int i=0;i<3;i++)
	{
		if(m[i][0]==x)
			m[i][1]--;
	}
}
void mor()
{
	if(m[2][1]>0 && m[1][1]==0)
	{
		m[1][0]=m[2][0];
		m[1][1]=m[2][1];
		m[2][0]=0;
		m[2][1]=0;
	}
	if(m[2][1]>0 && m[0][1]==0)
	{
		m[0][0]=m[2][0];
		m[0][1]=m[2][1];
		m[2][0]=0;
		m[2][1]=0;
	}
	if(m[1][1]>0 && m[0][1]==0)
	{
		m[0][0]=m[1][0];
		m[0][1]=m[1][1];
		m[1][0]=0;
		m[1][1]=0;
	}
}
int ekhtelaf()
{
	int t;
	mor();
	if(m[2][1]==0 && (abs(m[0][0]-m[1][0])<=1 || m[1][1]==0))
		return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int s1=0,s2=1,maxx=1;
	m[0][0]=a[0];
	m[0][1]=1;
	while(s2<=n)
	{
		//cout<<s1<<"  "<<s2<<endl;
		mor();
		//cout<<m[0][0]<<" "<<m[0][1]<<endl;
		//cout<<m[1][0]<<" "<<m[1][1]<<endl;
		//cout<<m[2][0]<<" "<<m[2][1]<<endl;
		if(ekhtelaf()==1)
		{
			maxx=max(maxx,s2-s1);
			ezaf(a[s2]);
			s2++;
		}
		else
		{
			menha(a[s1]);
			s1++;
		}
	}

	cout<<maxx;
}