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

char ch[maxn];
int len,a[maxn],s[maxn],f0,f1,f2,f[maxn],ans,cnt;

int main()
{
	scanf("%s",ch); len=strlen(ch);
	for(int i=0;i<len;i++) a[i]=ch[i]-'0';
	for(int i=0;i<len;i++)
	{
		int x=a[i];
		if(x%3==0)
		{
			cnt++;
			continue;
		}
		if(x%3==2&&(a[i+1]%3==1)&&i<len-1) cnt++,i++;
		else if(x%3==1&&(a[i+1]%3==2&&i<len-1)) cnt++,i++;
		else if(x%3==1&&(a[i+1]%3==1&&(a[i+2]%3==1)&&i<len-2)) cnt++,i+=2;
		else if(x%3==2&&(a[i+1]%3==2&&(a[i+2]%3==2)&&i<len-2)) cnt++,i+=2;
	}
	cout<<cnt<<endl;
	return 0;
}