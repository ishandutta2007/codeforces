#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,k;
vector <int> v1;
vector <string> v2;

int main()
{
	cin>>n>>m>>k;
	if(k>4*n*m-2*n-2*m) {puts("NO"); return 0;}
	else puts("YES");
	
	for(int i=1;i<=n-1&&k>0;i++)
	{
		if(k<m-1&&k>0) v1.push_back(k),v2.push_back("R"),k=0;
		else if(k>0&&m!=1) v1.push_back(m-1),v2.push_back("R"),k-=(m-1);
		
		if(k<3*(m-1)&&k>0)
		{
			int x=k/3,y=k%3;
			if(x!=0) v1.push_back(x),v2.push_back("DUL");
			if(y==1) v1.push_back(1),v2.push_back("D");
			else if(y==2) v1.push_back(1),v2.push_back("DU"); k=0;
		}
		else if(k>0&&m!=1) v1.push_back(m-1),v2.push_back("DUL"),k-=3*(m-1);
		
		if(k>0) v1.push_back(1),v2.push_back("D"),k--;
	}
	
	if(k>=m-1&&m!=1) v1.push_back(m-1),v2.push_back("R"),k-=(m-1);
	if(k>=m-1&&m!=1) v1.push_back(m-1),v2.push_back("L"),k-=(m-1);
	if(k>0) v1.push_back(k),v2.push_back("U");
	
	printf("%d\n",v1.size());
	for(int i=0;i<v1.size();i++) cout<<v1[i]<<" "<<v2[i]<<endl;
	return 0;
}