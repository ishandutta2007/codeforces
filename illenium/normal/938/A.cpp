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

inline bool judge(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y') return true;
	return false;
}

char s[maxn];
int n;

int main()
{
	cin>>n;
	cin>>s; s[n]=' ';
	for(int i=0;i<n;i++)
	{
		cout<<s[i];
		while(judge(s[i])&&judge(s[i+1])&&i<n) i++;
	}
	return 0;
}