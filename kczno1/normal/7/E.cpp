#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=100+5;
map<string,int>dp;//1:+- 2:*/
string ns,s;int n;
int nex[N];
int is[256];
int merge(int l,int r,int t)
{
	if(l==-1||r==-1)return -1;
	if(t=='+')
	{
	}
	else
	if(t=='-')
	{
		if(r&1)return -1;
	}
	else
	if(t=='*')
	{
		if((l&1)||(r&1))return -1;
	}
	else
	{
		if((l&1)||r)return -1;
	}
//	printf("is=%d %d\n",is[t],l|r|(1<<is[t]-1));
	return l|r|(1<<is[t]-1);
}
int solve(int l,int r)
{
//	printf("%d %d %c %c\n",l,r,s[l],s[r]);
//	cout<<s<<endl;
	if(l<r&&nex[l]==r)
	{
		int ans=solve(l+1,r-1);
		if(ans==-1)return -1;
		return 0;
	}
	vector<int>st;
	for(int i=l;;)
	{	
		int v;
		if(!nex[i])
		{
			string ns;
			while(i<=r&&!is[s[i]])
			{
				ns.push_back(s[i]);
				++i;
			}
			if(dp.count(ns))v=dp[ns];
			else v=0;
		}
		else
		{
			v=solve(i,nex[i]);
			i=nex[i]+1;
		}
		if(!st.empty()&&is[st.back()]==2)
		{
			int t=st.back();
			st.pop_back();
			st.back()=merge(st.back(),v,t);
		}
		else
		{
			st.push_back(v);
		}
		if(i>r)break;
		st.push_back(s[i++]);
	}
	auto it=st.begin();
	while(it!=st.end()-1)
	{
		it+=2;
		*it=merge(*(it-2),*it,*(it-1));
	}
//	rep(i,l,r)printf("%c",s[i]);
//	printf(" %d\n",*it);
	return *it;
}
int get()
{
	n=0;
	s.clear();
	getline(cin,ns);
	for(auto i:ns)
	{
		if(i!=' ')s.push_back(i);
	}
	n=s.size();
	memset(nex,0,sizeof(nex));
	//cout<<s<<endl;
	static vector<int>st;
	per(i,n-1,0)
	if(s[i]==')')st.push_back(i);
	else 
	if(s[i]=='('){nex[i]=st.back();st.pop_back();} 
//	cout<<s<<endl;
	return solve(0,n-1);	
}

int main()
{
//	freopen("1.in","r",stdin);
	is['+']=is['-']=1;
	is['*']=is['/']=2;
	int tt;
	cin>>tt;
	while(tt--)
	{
		int len=0;
		cin>>ns;
		while(/*cout<<ns<<endl,*/len+=ns.size(),len<7)cin>>ns;
		cin>>ns;
		dp[ns]=get();
	}
	if(get()!=-1)puts("OK");
	else puts("Suspicious");
}