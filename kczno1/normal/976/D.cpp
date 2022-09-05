#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
int tot;
vector<pii>l;

void solve(vector<int> d)
{
	int n=d.size();
	if(!n){tot=1;return ;}
	if(n==1)
	{
		tot=d[0]+1;
		rep(i,1,tot)
		rep(j,i+1,tot)l.push_back(make_pair(i,j));
		return ;
	}
	vector<int>_d;
	rep(i,1,n-2)_d.push_back(d[i]-d[0]);
	solve(_d);
	tot+=d[n-1]-d[n-2];
	rep(i,1,d[0])
	{
		++tot;
		rep(j,1,tot-1)l.push_back(make_pair(j,tot));
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	int n;
	cin>>n;
	vector<int>d(n);
	rep(i,0,n-1)cin>>d[i];
	solve(d);
	printf("%d\n",l.size());
	for(auto pr:l)printf("%d %d\n",pr.first,pr.second);
}