#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

const int SQ = 447;
struct Node {
	int l, r, i;
	bool operator<(const Node &n) const {
		if (l/SQ != n.l/SQ) return l/SQ < n.l/SQ;
		return l/SQ & 1 ? r < n.r : r > n.r;
	}
};

int N, M, Q;
int C[200001];
vector<Node> q;
int res[200001];
int A[200001][18]; // A[x][k] :  x k    (mod 2^k)
int B[18][200001]; // B[k][L] : k   L-1 <-> L   ? (mod 2^k)

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++)
	{
		int x;
		scanf("%d", &x);
		C[x] ^= 1;
	}
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		q.push_back({l, r, i});
	}
	sort(q.begin(), q.end());

	for(int i=1; i<=200000; i++)
	{
		for(int k=0; k<18; k++)
		{
			// [1, (1<<k)]   k   
			A[i][k] = (i%(1<<k)+1)%(1<<k);
		}
	}

	int L = 1, R = 0, XOR = 0; // [L,R]
	for(auto &it : q)
	{
		// B[], XOR 

		while(R < it.r)
		{
			R++;
			if (C[R]) // insert
			{
				for(int k=0; k<18; k++)
					B[k][A[R][k]] ^= 1;
				XOR ^= R-L;
			}
		}

		while(it.l < L)
		{
			// L -> L-1     ?
			for(int k=0; k<18; k++)
				if (B[k][L&((1<<k)-1)])
					XOR ^= 1<<k;
			
			L--;
			if (C[L]) // insert
			{
				for(int k=0; k<18; k++)
					B[k][A[L][k]] ^= 1;
				//XOR ^= 0;
			}
		}

		while(it.r < R)
		{
			if (C[R]) // delete
			{
				for(int k=0; k<18; k++)
					B[k][A[R][k]] ^= 1;
				XOR ^= R-L;
			}
			R--;
		}

		while(L < it.l)
		{
			if (C[L]) // delete
			{
				for(int k=0; k<18; k++)
					B[k][A[L][k]] ^= 1;
				//XOR ^= 0;
			}
			L++;

			// L -> L+1     ?
			for(int k=0; k<18; k++)
				if (B[k][L&((1<<k)-1)])
					XOR ^= 1<<k;
		}

		res[it.i] = XOR;
	}

	string ans;
	for(int i=1; i<=Q; i++)
	{
		//cout << i << " : " << res[i] << "\n";
		if (res[i])
			ans += 'A';
		else
			ans += 'B';
	}
	cout << ans << "\n";
	return 0;
}