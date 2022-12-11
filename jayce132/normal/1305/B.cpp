#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

vector<int>a,b;

const int maxn=2e5+20;

int n;
char str[maxn];

inline void init()
{
	scanf("%s",str+1);n=strlen(str+1);
	for(int i=1,j=n;i<j;)
	{
		if(str[i]==')')i++;
		else if(str[j]=='(')j--;
		else {
			a.push_back(i); b.push_back(j);
			i++;j--;
		}
	}
	if(a.empty())puts("0");
	else {
		puts("1");
		printf("%d\n",SZ(a)+SZ(b));
		for(int x:a)printf("%d ",x);
		reverse(b.begin(),b.end());
		for(int x:b)printf("%d ",x);
	}
}

int main()
{
	init();
	return 0;
}