#include<iostream>
#include<math.h>
using namespace std;
int t(int x,int y)
{
	if(x-y==1 || y-x==1)
		return 1;
	return 0;
}
int t1(int x,int y,int z)
{
	if(((abs(x-y)==1 && abs(x-z)==1)||(abs(x-y)==1 && abs(y-z)==1)||(abs(z-y)==1 && abs(x-z)==1))&&(x!=y && y!=z && z!=x))
		return 1;
	return 0;
}
int main()
{
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	int k=2;
	if(s1==s2 || s2==s3 || s3==s1)
		k=1;
	if(s1[1]==s2[1])
	{
		if(abs((int(s1[0]))-(int(s2[0])))==2)
			k=1;
		if(t((int(s1[0])-48),(int(s2[0]))-48)==1)
			k=1;
	}
	if(s1[1]==s3[1])
	{
		if(abs((int(s1[0]))-(int(s3[0])))==2)
			k=1;
		if(t(int(s1[0])-48,int(s3[0])-48)==1)
			k=1;
	}
	if(s2[1]==s3[1])
	{
		if(abs((int(s3[0]))-(int(s2[0])))==2)
			k=1;
		if(t(int(s2[0])-48,int(s3[0])-48)==1)
			k=1;
	}
	
	if(s1==s2 && s2==s3)
		k=0;
	if(s1[1]==s2[1] && s2[1]==s3[1] && t1(s1[0],s2[0],s3[0])==1)
		k=0;
	cout<<k;
}