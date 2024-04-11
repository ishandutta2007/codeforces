#include<iostream>
using namespace std;
int kh[150000][2];
int a[27][150001]={0},andisa[32]={0};
int b[27][150001]={0},andisb[32]={0};
int andis(char x)
{
	if(x=='?')
		return 26;
	return int(x)-97;
}
int main()
{

	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<n;i++)
	{
		a[andis(s1[i])][andisa[andis(s1[i])]]=i+1;
		andisa[andis(s1[i])]++;
		b[andis(s2[i])][andisb[andis(s2[i])]]=i+1;
		andisb[andis(s2[i])]++;
	}
	int t=0,tedada=andisa[26],tedadb=andisb[26];
	
	
	
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<min(andisb[i],andisa[i]);j++)
		{
			//cout<<a[i][j]<<" "<<b[i][j]<<endl;
			kh[t][0]=a[i][j];
			kh[t][1]=b[i][j];
			t++;
		}
		if(i<26)
		{
		if(andisb[i]<andisa[i])
		{
			int p=tedadb;
			for(int j=andisb[i];j<min(andisa[i],andisb[i]+p);j++)
			{
				kh[t][0]=a[i][j];
				kh[t][1]=b[26][tedadb-1];
				tedadb--;
				t++;
			}
		}
		if(andisb[i]>andisa[i])
		{
			int p=tedada;
			for(int j=andisa[i];j<min(andisb[i],andisa[i]+p);j++)
			{
				kh[t][0]=a[26][tedada-1];
				kh[t][1]=b[i][j];
				tedada--;
				t++;
			}
		}
		}
	}
	for(int i=0;i<min(tedada,tedadb);i++)
	{
		kh[t][0]=a[26][i];
		kh[t][1]=b[26][i];
		t++;
	}
	cout<<t<<endl;
	for(int i=0;i<t;i++)
	{
		cout<<kh[i][0]<<" "<<kh[i][1]<<endl;
	}
}