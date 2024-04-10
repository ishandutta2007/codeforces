#include<bits/stdc++.h>
using namespace std;
struct p{
	int step , n;
	p(int a){
		step = 0;
		n = a;
	}
	p(p r , int m)
	{
		step = r.step + 1;
		if(m)	n = r.n * 2;
		else	n = r.n - 1;
	}
};
bool vis[20001];
int main()
{
	int n , m , i = 0 , f = 0;
	cin >> n >> m;
	p ans(n);
	vis[n] = 1;
	queue < p > q;
	q.push(ans);
	while(!q.empty())
	{
		p ans1(q.front() , 0) , ans2(q.front() , 1);
		q.pop();
		if(ans1.n == m || ans2.n == m)
		{
			cout << ans1.step;
			return 0;
		}
		if(!vis[ans1.n] && ans1.n <= max(2 * m , n) && ans1.n >= 1)
		{
			q.push(ans1);
			vis[ans1.n] = 1;
		}
		if(!vis[ans2.n] && ans2.n >= 1 && ans2.n <= max(2 * m , n))
		{
			q.push(ans2);
			vis[ans2.n] = 1;
		}
	}
	return 0;
}