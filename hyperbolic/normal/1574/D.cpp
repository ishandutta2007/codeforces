#include <stdio.h>
#include <set>
#include <queue>
#include <vector>

int a;
struct str{
	std::vector<int> W;
	int val;
	long long int val2;
}init;
bool operator<(str A, str B)
{
	return A.val<B.val;
}
std::pair<long long int, long long int> hash(str A)
{
	long long int ans1 = 0, ans2 = 0;
	long long int MOD1 = 998244353, MOD2 = 1000000007;
	for(int i=1;i<=a;i++)
	{
		ans1 *= 99999971, ans1 %= MOD1;
		ans1 += A.W[i], ans1 %= MOD1;
		ans2 *= 99999971, ans2 %= MOD2;
		ans2 += A.W[i], ans2 %= MOD2;
	}
	return std::make_pair(ans1,ans2);
}

std::set<std::pair<long long int, long long int> > S,T;
std::priority_queue<str> Q;
std::vector<int> V[110];
void func()
{
	Q.push(init);
	while(!Q.empty())
	{
		str A = Q.top();
		//for(int i=1;i<=a;i++) printf("%d ",A.W[i]);
		//printf(": %d !!\n",A.val);
		
		Q.pop();
		if(S.find(hash(A))!=S.end()) continue;
		S.insert(hash(A));
		if(T.find(hash(A))==T.end())
		{
			for(int i=1;i<=a;i++) printf("%d ",A.W[i]);
			return;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(A.W[i]>1)
			{
				A.val -= V[i][A.W[i]];
				A.W[i]--;
				A.val += V[i][A.W[i]];
				Q.push(A);
				A.val -= V[i][A.W[i]];
				A.W[i]++;
				A.val += V[i][A.W[i]];
			}
		}
	}
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		V[i].push_back(0);
		for(int j=1;j<=b;j++)
		{
			int c;
			scanf("%d",&c);
			V[i].push_back(c);
		}
	}
	
	int b;
	scanf("%d",&b);
	for(int j=1;j<=b;j++)
	{
		str A;
		A.W.push_back(0);
		A.val = 0;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			A.W.push_back(c);
			A.val += V[i][c];
		}
		
		//for(int i=1;i<=a;i++) printf("%d ",A.W[i]);
		//printf(" : %d ??\n",A.val);
		T.insert(hash(A));
	}
	
	init.W.push_back(0);
	init.val = 0;
	for(int i=1;i<=a;i++)
	{
		init.W.push_back(V[i].size()-1);
		init.val += V[i].back();
	}
	
	func();
}