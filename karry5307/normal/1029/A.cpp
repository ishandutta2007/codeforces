#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll last,len,cnt;
string str,res,temp;
inline ll connect(string a,string b)
{
	for(register int i=min(a.length(),b.length())-1;i>=0;i--)
	{
		string s=a.substr(a.length()-i),t=b.substr(0,i);
		if(s==t)
		{
			return i;
		}
	}
}
int main()
{
	cin>>len>>cnt>>str;
	last=connect(str,str);
	res=str;
	temp=str,temp=temp.erase(0,last);
	for(register int i=0;i<cnt-1;i++)
	{
		res+=temp;
	} 
	cout<<res;
}