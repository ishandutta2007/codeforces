#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
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

int p[20]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49},cnt;
string s;

int main()
{
	for(int i=1;i<=19;i++)
	{
		cout<<p[i]<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='y') cnt++;
	}
	if(cnt>=2) cout<<"composite"<<endl;
	else puts("prime");
	fflush(stdout);
	return 0;
}