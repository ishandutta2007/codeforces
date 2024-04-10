#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 10;
typedef pair<int, int> PII;

priority_queue<int> P, Q;
PII a[MAXN], b[MAXN];
int visa[MAXN], visb[MAXN];

char s[MAXN];

int main(){
	int n;
	cin>>n;
	int p = 0, q = 0;
	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%s%d%d", s, &x, &y);
		if (s[0] == 'M'){
			a[++p] = PII(x, y);
		}
		else
			b[++q] = PII(x, y);
	}
	sort(a + 1, a + p + 1);
	sort(b + 1, b + q + 1);
	for(int i = 1; i <= n; i++)
		visa[i] = visb[i] = 0;
	int cnt = 0;
	for(int i = 1; i <= 366; i++){
		int x = 0, y = 0;
		for(int j = 1; j <= p; j++)
			if (a[j].first <= i && a[j].second >= i)
				x++;
		for(int j = 1; j <= q; j++)
			if (b[j].first <= i && b[j].second >= i)
				y++;
		cnt = max(cnt, min(x, y));
		/*
		int x = -1, y = -1;
		for(int j = 1; j <= p; j++)
			if (!visa[j] && a[j].first <= i && a[j].second >= i && (x == -1 || (a[j].second < a[x].second)))
				x = j;
		for(int j = 1; j <= q; j++)
			if (!visb[j] && b[j].first <= i && b[j].second >= i && (y == -1 || (b[j].second < b[x].second)))
				y = j;
		if (x != -1 && y != -1){
			visa[x] = visb[y] = 1;
			cnt++;
		}*/
	}
	cout<<cnt * 2<<endl;
	return 0;
}