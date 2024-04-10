#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	string s;
	cin>>s;
	map<string,int> M;
	for(int i=0;i<s.length();i++)
		for(int j=i;j<s.length();j++)
		{
			bool ok=true;
			for(int k=i;k<=j;k++)
				if(s[k]!='4'&&s[k]!='7')
					ok=false;
			if(ok)
				M[s.substr(i,j-i+1)]++;
		}
	int ans=0;
	string res="-1";
	map<string,int>::iterator it;
	for(it=M.begin();it!=M.end();it++)
		if(it->second>ans)
		{
			ans=it->second;
			res=it->first;
		}
	cout<<res<<endl;
	return 0;
}