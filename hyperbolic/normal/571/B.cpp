#include <stdio.h>
#include <algorithm>
#include <map>

long long int MAX = 1;
int A,B;
int x[300010];
int type1, type2;
long long int check[5010][5010];
long long int func(int s, int t)
{
	if(s<0) return MAX;
	if(t<0) return MAX;
	if(s==0&&t==0) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	int start = 1 + type1*(A-s) + type2*(B-t);
	long long int s1 = func(s-1,t) + x[start+type1-1]-x[start];
	long long int s2 = func(s,t-1) + x[start+type2-1]-x[start];
	return check[s][t] = s1<s2?s1:s2;
}

std::map<int,int> M;
int count[5010];
int main()
{
	for(int i=1;i<=17;i++) MAX*=10;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<=b;i++) for(int j=0;j<=b;j++) check[i][j] = -1;
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) count[i%b]++;
	for(int i=0;i<b;i++) M[count[i]]++;
	std::map<int,int> ::iterator it;
	it = M.begin();
	type1 = (it->first);
	A = (it->second);
	it++;
	if(it==M.end())
	{
		type2 = 0;
		B = 0;
	}
	else
	{
		type2 = (it->first);
		B = (it->second);
	}
	printf("%lld",func(A,B));
}