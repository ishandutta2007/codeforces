#include<iostream>
#include<string>
using namespace std;
int bozorg(int u,int y)
{
	if(u>y)
		return u;
	return y;
}
int main()
{
	int n2=0,n1=0,k1=0;
	cin >> n1 >> n2;
	n2=n2-1;
	int s[n1];
	for(int i=0;i<n1;i++)
		cin >> s[i];
	for(int i=1;i<=bozorg(n1-n2-1,n2);i++){
		if(n2+i>=n1 && s[n2-i]>0)
			k1++;
		if(n2-i<0 && s[n2+i]>0)
			k1+=1;
		if(n2-i>-1 && n2+i<n1 && s[n2+i]==1 && s[n2-i]==1)
			k1+=2;
	}
	k1+=s[n2];
	cout << k1;	
	
}