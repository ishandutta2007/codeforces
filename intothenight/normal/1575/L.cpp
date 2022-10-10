#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N;
int A[200201];
int dp[200201];
int seg[530000];

int Update(int idx, int val, int n, int l, int r)
{
	if (r < idx || idx < l) return seg[n];
	if (l == r) return seg[n] = max(seg[n], val); // max change
	int mid = l+r>>1;
	return seg[n] = max(Update(idx, val, n<<1, l, mid), Update(idx, val, n<<1|1, mid+1, r));
}

int Query(int L, int R, int n, int l, int r)
{
	if (r < L || R < l) return 0;
	if (L <= l && r <= R) return seg[n];
	int mid = l+r>>1;
	return max(Query(L, R, n<<1, l, mid), Query(L, R, n<<1|1, mid+1, r)); //
}

int Delete(int idx, int n, int l, int r)
{
	if (r < idx || idx < l) return seg[n];
	if (l == r) return seg[n] = 0;
	int mid = l+r>>1;
	return seg[n] = max(Delete(idx, n<<1, l, mid), Delete(idx, n<<1|1, mid+1, r));
}

void dnc(int L, int R)
{
	if (L == R) { dp[L] = max(dp[L], 1); return; } // ;;
	int mid = L+R>>1;

	dnc(L, mid);

	vector<array<int, 3> > u, q;
	for(int i=L; i<=mid; i++)
		if (A[i] <= i)
			u.push_back({i-A[i], A[i], dp[i]});
	for(int i=mid+1; i<=R; i++)
		if (A[i] <= i)
			q.push_back({i-A[i]+1, A[i], i});
	sort(u.begin(), u.end());
	sort(q.begin(), q.end());
	
	// aj < ai && bj < bi
	int j = 0;
	for(auto [a,b,i] : q)
	{
		while(j < u.size() && u[j][0] < a)
		{
			Update(u[j][1], u[j][2], 1, 1, 200000);
			j++;
		}
		dp[i] = max(dp[i], Query(1, b-1, 1, 1, 200000) + 1);
	}

	// clear :  
	for(auto [a,b,x] : u)
		Delete(b, 1, 1, 200000);

	dnc(mid+1, R); //  :  
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> A[i];

	//     
	dnc(1, N);

	int res = 0;
	for(int i=1; i<=N; i++)
	{
		if (A[i] <= i)
			res = max(res, dp[i]);

		// cout << dp[i] << " ";
	}
	// cout << "\n";

	cout << res << "\n";
	return 0;
}