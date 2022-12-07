#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 200005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N];
std::set<int>S;
std::set<int>::iterator it;
void Solve()
{
	S.insert(A[1]);
	for(int i=2;i<=n;i++)
	{
		if(A[i]==A[i-1]) continue;
		it=S.find(A[i-1]),it++;
		if(A[i]>A[i-1]&&it!=S.end()&&A[i]>*it) return void(puts("NO"));
		it--;
		if(A[i]<A[i-1]&&it!=S.begin()&&A[i]<*(--it)) return void(puts("NO"));
		S.insert(A[i]);
	}
	puts("YES");
}
void clear()
{
	S.clear();
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		Solve();
	}
	return 0;
}