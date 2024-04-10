#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N, M, K;
int A[1010][1010];
const int dir[4][2] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}};
int p[1010101];

int Find(int n)
{
	if (n == p[n]) return n;
	return p[n] = Find(p[n]);
}
void Union(int a, int b) // b  .
{
	a = Find(a); b = Find(b);
	if (a == b) return;
	p[a] = b;
}

int f(int y, int x)
{
	return (y-1) * 1000 + (x-1);
}

pair<int, int> g(int n)
{
	return {n/1000 + 1, n%1000 + 1};
}

int main()
{
	for(int i=0; i<1010101; i++)
		p[i] = i;
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin >> A[i][j];

	while(K--)
	{
		int x;
		cin >> x;

		int y = 1;
		while(y <= N)
		{
			if (Find(f(y, x)) == f(y, x))
			{
				int d = A[y][x];
				A[y][x] = 2;
				if (y+1 <= N) Union(f(y, x), f(y+1, x));

				y += dir[d][0], x += dir[d][1];
			}
			else
			{
				auto [ny,nx] = g(Find(f(y, x)));
				y = ny; x = nx;
			}
		}
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}