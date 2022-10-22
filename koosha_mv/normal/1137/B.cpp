#include<iostream>
#include<cstdio>
#include<cstring>
#define ma 500500
 
using  namespace std;
int f[ma],b[ma],len,mid,m1,m2,k1,k2;
char s[ma],t[ma];
 
int main()
{
	scanf(" %s",s); scanf(" %s",t);
	len=strlen(t);
	b[0]=t[0]-'0';b[1]=b[0]+t[1]-'0';
	for(int i=2;i<=len;i++)
	{
		b[i]=b[i-1]+t[i]-'0';	mid=f[i-1]; 
		while(t[mid]!=t[i-1]&&mid) mid=f[mid];
		f[i]=t[mid]==t[i-1]?++mid:0;
	}
	m1=b[len-1]-b[f[len]-1]; m2=len-f[len]-m1;
	for(int i=0;s[i]!=0;i++) 
		if(s[i]=='1') k1++;
		else k2++;
	if(k1<b[len-1]||k2<len-b[len-1])
	{
		printf("%s",s); return 0;
	}
	printf("%s",t); k1-=b[len-1];k2-=(len-b[len-1]);
	while(k1>=m1&&k2>=m2)
	{
		for(int i=f[len];i<len;i++) printf("%c",t[i]);
		k1-=m1;k2-=m2;
	}
	while(k1--) printf("1");
	while(k2--) printf("0");
}