#include <bits/stdc++.h>
using namespace std;
vector<int> v1,v2,v3;
#define vi vector<int>
#define pb push_back
vi pos,neg,zero;
void print(vi& v)
{
	cout<<v.size()<<" ";
	for(int i = 0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}
int main()
{
	int n,x;
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&x);
		if(x>0)
			v1.pb(x);
		else if(x < 0)
			neg.pb(x);
		else
			v3.pb(x);
	}

	v2.pb(neg[0]);
	int st = 1;
	if(v1.empty())
	{
		v1.pb(neg[1]);
		v1.pb(neg[2]);
		st = 3;
	}
	for(int i = st;i<neg.size();i++)
		v3.pb(neg[i]);
	print(v2);
	print(v1);
	print(v3);
}