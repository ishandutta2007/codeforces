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

int n;
string s;
map<string,int> mp;
map<string,string> mp2;

int main()
{
	cin>>n; cout<<6-n<<endl;
	mp2["red"]="Reality"; mp2["purple"]="Power";
	mp2["green"]="Time"; mp2["yellow"]="Mind";
	mp2["blue"]="Space"; mp2["orange"]="Soul";
	for(int i=1;i<=n;i++) cin>>s,mp[mp2[s]]=1;
	if(!mp["Time"]) puts("Time");
	if(!mp["Space"]) puts("Space");
	if(!mp["Power"]) puts("Power");
	if(!mp["Reality"]) puts("Reality");
	if(!mp["Mind"]) puts("Mind");
	if(!mp["Soul"]) puts("Soul");
	return 0;
}