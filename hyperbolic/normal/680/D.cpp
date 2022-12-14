#include <stdio.h>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
struct str{
	int count;
	long long int value;
};
std::map<long long int,str> M;
long long int triple(long long int k)
{
	return k*k*k;
}
int Lvalue(long long int k)
{
	//(int)k^1/3
	int min = 1, max = 100000,h,ans;
	while(min<=max)
	{
		h = (min+max)/2;
		if(triple(h)>k) max = h-1;
		else
		{
			ans = h;
			min = h+1;
		}
	}
	return ans;
}
str func(long long int k)
{
	if(k==0)
	{
		str A;
		A.count = 0;
		A.value = 0;
		return A;
	}
	if(M.find(k)!=M.end()) return M[k];
	//0~k  .
	int s = Lvalue(k);
	str A1 = func(k-triple(s));
	A1.count++,A1.value+=triple(s);
	str A2 = func(triple(s)-1);
	
	if(A1.count==A2.count)
	{
		if(A1.value<A2.value) return M[k]=A2;
		else return M[k]=A1;
	}
	else if(A1.count<A2.count) return M[k]=A2;
	else return M[k]=A1;
}
std::priority_queue<long long int> Q;
std::stack<long long int> St;
int main()
{
	long long int a;
	scanf("%lld",&a);
	
	/*Q.push(a);
	long long int prev = 0;
	while(!Q.empty())
	{
		long long int k = Q.top();
		Q.pop();
		//printf("%lld %d\n",k,Lvalue(k));
		if(k==0) break;
		if(k==prev) continue;
		St.push(k);
		int s = Lvalue(k);
		if(M.find(k-triple(s))==M.end()) Q.push(k-triple(s)),M[k-triple(s)]={1,0};
		if(M.find(triple(s)-1)==M.end()) Q.push(triple(s)-1),M[triple(s)-1]={1,0};
		prev = k;
	}
	printf("%d\n",St.size());*/
	int s = Lvalue(a);
	for(int i=2;i<=s;i++) func(triple(i)-1);
	str A = func(a);
	printf("%d %I64d\n",A.count,A.value);
}