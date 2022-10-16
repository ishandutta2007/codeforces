#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int need[522001];
int ge[225001];
int p[9];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, K;
	cin >> N >> M >> K;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> need[i] >> ge[i];
		int ans = 0;
		if (need[i] > M)
			ans += 2;
		if (need[i] == M)
			ans++;
		if (ge[i] > K)
			ans += 6;
		if (ge[i] == K)
			ans += 3;
		p[ans]++;
	}
	int rans =  p[0] + p[1] + p[2];
	int sans = p[6] + p[7] + p[8];
	int wans = p[0] + p[3] + p[6];
	int eans = p[2] + p[5] + p[8];
	vector<int>yee = { rans,sans,wans,eans };
	sort(yee.begin(), yee.end());
	cout << yee[3] << '\n';
	if (yee[3] == rans)
		cout << M  << ' ' << K-1;
	else if (yee[3] == sans)
		cout << M  << ' ' << K+1;
	else if (yee[3] == wans)
		cout << M - 1 << ' ' << K;
	else if (yee[3] == eans)
		cout << M + 1 << ' ' << K;

}