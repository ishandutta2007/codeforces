#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int K=1e3;
mt19937 gen(84819314);
vector<int> poss;
int p(int l,int r)
{
	return uniform_int_distribution<int>{l,r}(gen);
}
int main()
{
	int n,x,id,mx,nxt,a,y,z,i;
	cin>>n>>id>>x;
	cout<<"? "<<id<<endl;
	fflush(stdout);
	cin>>mx>>nxt;
	for(i=1;i<=n;i++)
		poss.push_back(i);
	for(i=1;i<K && !poss.empty();i++)
	{
		int tmp=p(0,poss.size()-1);
		a=poss[tmp];
		swap(poss[tmp],poss.back());
		poss.pop_back();
		cout<<"? "<<a<<endl;
		fflush(stdout);
		cin>>y>>z;
		if(y<=x && y>mx)
		{
			mx=y;
			id=a;
			nxt=z;
		}
	}
	//cerr<<mx<<"\n";
	while(mx<x)
	{
		if(nxt==-1)
		{
			cout<<"! -1"<<endl;
			fflush(stdout);
			return 0;
		}
		id=nxt;
		cout<<"? "<<id<<endl;
		fflush(stdout);
		cin>>mx>>nxt;
		i++;
	}
	cout<<"! "<<mx<<endl;
	fflush(stdout);
	return 0;
}