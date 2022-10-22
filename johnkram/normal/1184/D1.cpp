#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n,m,t,i,j,s;
vector<int> a;
int main()
{
	scanf("%d%d%*d%d",&n,&m,&t);
	a.resize(n,0);
	a[m-1]=1;
	s=m;
	while(t--)
	{
		scanf("%d%d",&i,&j);
		if(i)a.insert(a.begin()+j-1,0);
		else if(s<=j)a.erase(a.begin()+j,a.end());
		else a.erase(a.begin(),a.begin()+j);
		n=a.size();
		for(i=0;i<n;i++)if(a[i])s=i+1;
		cout<<n<<' '<<s<<endl;
	}
	return 0;
}