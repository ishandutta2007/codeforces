#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int D = 200000;
const int MaxN = 100000;
const int MaxM = MaxN * 2 + D * 2;
const int INF = 0x3f3f3f3f;

int n;
int vl[MaxM + 1], vr[MaxM + 1];
int prel[MaxM + 1], prer[MaxM + 1];
int sufl[MaxM + 1], sufr[MaxM + 1];

int main()
{
	cin >> n;

	fill(vl, vl + MaxM + 1, +INF);
	fill(vr, vr + MaxM + 1, -INF);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		int p = x + y + D, q = x - y;
		vl[p] = min(vl[p], q);
		vr[p] = max(vr[p], q);
	}

	for (int i = 0; i < 2; ++i)
		prel[i] = vl[i], prer[i] = vr[i];
	for (int i = 2; i <= MaxM; ++i)
	{
		prel[i] = min(prel[i - 2], vl[i]);
		prer[i] = max(prer[i - 2], vr[i]);
	}

	for (int i = MaxM; i > MaxM - 2; --i)
		sufl[i] = vl[i], sufr[i] = vr[i];
	for (int i = MaxM - 2; i >= 0; --i)
	{
		sufl[i] = min(sufl[i + 2], vl[i]);
		sufr[i] = max(sufr[i + 2], vr[i]);
	}

	s64 res = 0;
	for (int i = 2; i <= MaxM; ++i)
	{
		int l = max(prel[i - 2], sufl[i]);
		int r = min(prer[i - 2], sufr[i]);
		res += max(r - l, 0);
	}

	cout << res / 2 << endl;

	return 0;
}