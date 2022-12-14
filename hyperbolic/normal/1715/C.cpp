#include <stdio.h>
#include <set>

long long int ans = 0;
int a,b;
std::set<int> start;
int x[100010];
void insert(int k)
{
	if(start.find(k)!=start.end()) return;
	std::set<int> ::iterator it2 = start.lower_bound(k+1);
	std::set<int> ::iterator it1 = it2;
	it1--;
	int L = (*it1), R = (*it2)-1;
	if(L<=R)
	{
		ans -= (long long int)(L-1)*L/2;
		ans -= (long long int)(a-R)*(a-R+1)/2;
	}
	//L ~ k-1, k ~ R
	if(L<=k-1)
	{
		ans += (long long int)(L-1)*L/2;
		ans += (long long int)(a-(k-1))*(a-(k-1)+1)/2;
	}
	if(k<=R)
	{
		ans += (long long int)(k-1)*(k)/2;
		ans += (long long int)(a-(R))*(a-(R)+1)/2;
	}
	start.insert(k);
}

void erase(int k)
{
	if(start.find(k)==start.end()) return;
	std::set<int> ::iterator it2 = start.lower_bound(k+1);
	std::set<int> ::iterator it1;
	int L = k, R = (*it2)-1;
	if(L<=R)
	{
		ans -= (long long int)(L-1)*L/2;
		ans -= (long long int)(a-R)*(a-R+1)/2;
	}
	
	it1 = it2;
	it1--;
	it1--;
	L = (*it1), R = k-1;
	if(L<=R)
	{
		ans -= (long long int)(L-1)*L/2;
		ans -= (long long int)(a-R)*(a-R+1)/2;
	}
	L = (*it1), R = (*it2)-1;
	if(L<=R)
	{
		ans += (long long int)(L-1)*L/2;
		ans += (long long int)(a-R)*(a-R+1)/2;
	}
	start.erase(k);
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) if(x[i]!=x[i-1]) start.insert(i);
	start.insert(a+1);
	
	for(std::set<int> ::iterator it = start.begin();;it++)
	{
		std::set<int> ::iterator it2 = it;
		it2++;
		if(it2==start.end()) break;
		
		int L = (*it), R = (*it2)-1;
		if(L<=R)
		{
			ans += (long long int)(L-1)*L/2;
			ans += (long long int)(a-R)*(a-R+1)/2;
		}
	}
	while(b--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		insert(c);
		insert(c+1);
		x[c] = d;
		if(x[c]==x[c+1]) erase(c+1);
		if(x[c]==x[c-1]) erase(c);
		
		long long int val = start.size() - 1;
		val *= (long long int)a*(a+1)/2;
		printf("%lld\n",val-ans);
	}
}