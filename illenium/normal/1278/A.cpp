#pragma GCC optimize(2)
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

char s[maxn],s1[maxn];
map <vector <int>,int> mp;
vector <int> vec,tmp;

int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1); scanf("%s",s1+1); mp.clear(); vec.clear(); tmp.clear();
		int f=0;
		for(int i=0;i<26;i++) vec.push_back(0),tmp.push_back(0);
		for(int i=1;i<=strlen(s+1);i++) vec[s[i]-'a']++;
		for(int i=1;i<=strlen(s+1);i++) tmp[s1[i]-'a']++;
		if(tmp==vec) puts("YES"),f=1;
		if(f==0)
		for(int i=strlen(s+1)+1;i<=strlen(s1+1);i++)
		{
			tmp[s1[i]-'a']++;
			tmp[s1[i-strlen(s+1)]-'a']--;
			if(tmp==vec) {f=1; puts("YES"); break;}
		}
		if(f==0) puts("NO");
	}
	return 0;
}