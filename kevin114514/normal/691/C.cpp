#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	string S;
	cin>>S;
	int dot=-1;
	for(int i=0;i<S.length();i++)
		if(S[i]=='.')
			dot=i;
	if(dot==-1)
	{
		int cnt1=0;
		while(S.length())
		{
			cnt1++;
			if(S[S.length()-1]=='0')
				S.resize(S.length()-1);
			else break;
		}
		cnt1--;
		int fst;
		for(fst=0;fst<S.length();fst++)
			if(S[fst]!='0')
				break;
		cout<<S[fst];
		if(fst<S.length()-1)
			cout<<".";
		int cnt=0;
		for(int i=fst+1;i<S.length();i++)
		{
			cout<<S[i];
			cnt++;
		}
		if(cnt+cnt1)
			cout<<"E"<<cnt+cnt1<<endl;
		return 0;
	}
	int fst;
	for(fst=0;fst<S.length();fst++)
		if(S[fst]!='0')
			break;
	int lst;
	for(lst=S.length()-1;lst>=0;lst--)
		if(S[lst]!='0')
			break;
	if(S[fst]=='.')
	{
		int cnt=0;
		for(fst=fst+1;fst<S.length();fst++)
		{
			if(S[fst]!='0')
				break;
			cnt++;
		}
		if(fst==lst)
		{
			cout<<S[fst]<<"E-"<<cnt+1<<endl;
		}
		else
		{
			cout<<S[fst]<<".";
			for(int i=fst+1;i<=lst;i++)
				cout<<S[i];
			cout<<"E-"<<cnt+1<<endl;
		}
	}
	else
	{
		for(;lst>=0;lst--)
			if(S[lst]!='.'&&S[lst]!='0')
				break;
		if(lst==fst)
		{
			cout<<S[fst];
			if(fst<dot-1)
				cout<<"E"<<dot-fst-1;
			return 0;
		}
		cout<<S[fst]<<".";
		for(int i=fst+1;i<=lst;i++)
			if(S[i]!='.')
				cout<<S[i];
		if(fst<dot-1)
			cout<<"E"<<dot-fst-1;
	}
	return 0;
}