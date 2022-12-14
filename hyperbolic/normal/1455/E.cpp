#include <stdio.h>
#include <algorithm>

long long int MAX = 1;
long long int abs(long long int k)
{
	return k>0?k:-k;
}

std::pair<long long int,long long int> P[5];
int x[5];

std::pair<long long int,long long int> func(std::pair<long long int,long long int> A, std::pair<long long int,long long int> B)
{
	if(A.first>A.second)
	{
		long long int t = A.first;
		A.first = A.second;
		A.second = t;
	}
	if(B.first>B.second)
	{
		long long int t = B.first;
		B.first = B.second;
		B.second = t;
	}
	
	long long int min=MAX,max=0;
	min = min<abs(A.first-B.first)?min:abs(A.first-B.first);
	max = max>abs(A.first-B.first)?max:abs(A.first-B.first);
	min = min<abs(A.first-B.second)?min:abs(A.first-B.second);
	max = max>abs(A.first-B.second)?max:abs(A.first-B.second);
	min = min<abs(A.second-B.first)?min:abs(A.second-B.first);
	max = max>abs(A.second-B.first)?max:abs(A.second-B.first);
	min = min<abs(A.second-B.second)?min:abs(A.second-B.second);
	max = max>abs(A.second-B.second)?max:abs(A.second-B.second);
	if((A.first>B.first?A.first:B.first)<=(A.second<B.second?A.second:B.second)) min = 0;
	return std::make_pair(min,max);
}

int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=4;i++) scanf("%lld%lld",&P[i].first,&P[i].second);
		
		x[1] = 1, x[2] = 2, x[3] = 3, x[4] = 4;
		long long int ans = MAX;
		
		do{
			long long int s1 = abs(P[x[1]].first-P[x[2]].first) + abs(P[x[3]].first-P[x[4]].first);
			long long int s2 = abs(P[x[1]].second-P[x[3]].second) + abs(P[x[2]].second-P[x[4]].second);
			
			std::pair<long long int,long long int> P1,P2;
			P1 = std::make_pair(P[x[1]].first,P[x[2]].first);
			P2 = std::make_pair(P[x[3]].first,P[x[4]].first);
			std::pair<long long int,long long int> L = func(P1,P2);
			P1 = std::make_pair(P[x[1]].second,P[x[3]].second);
			P2 = std::make_pair(P[x[2]].second,P[x[4]].second);
			std::pair<long long int,long long int> R = func(P1,P2);
			long long int K = func(L,R).first;
			
			ans = ans<s1+s2+2*K?ans:s1+s2+2*K;
			
			s1 = abs(P[x[1]].first-P[x[2]].first) + abs(P[x[3]].first-P[x[4]].first);
			s2 = abs(P[x[1]].second-P[x[4]].second) + abs(P[x[2]].second-P[x[3]].second);
			
			P1 = std::make_pair(P[x[1]].first,P[x[2]].first);
			P2 = std::make_pair(P[x[3]].first,P[x[4]].first);
			L = func(P1,P2);
			P1 = std::make_pair(P[x[1]].second,P[x[4]].second);
			P2 = std::make_pair(P[x[2]].second,P[x[3]].second);
			R = func(P1,P2);
			K = func(L,R).first;
			
			ans = ans<s1+s2+2*K?ans:s1+s2+2*K;
		}while(std::next_permutation(x+1,x+5));
		printf("%lld\n",ans);
	}
}