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

void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

ll a,b;

int main()
{
	cin>>a>>b;
	while(1)
	{
		if(a==0||b==0) break;
		if(a>=2*b) {a%=(2*b); continue;}
		else if(b>=2*a) {b%=(2*a); continue;}
		break;
	}
	cout<<a<<" "<<b;
	return 0;
}