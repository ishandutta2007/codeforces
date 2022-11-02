#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m, a[1005][1005], low[2][1005][1005], hig[2][1005][1005];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++) {
		vector<pii> V;
		for(int j=1;j<=m;j++) {
			V.push_back({a[i][j], j});
		}
		sort(V.begin(), V.end());
		int C = 0;
		for(int j=0;j<(int)V.size();j++) {
			int I = j;
			while(I+1 < (int)V.size() && V[I+1].X == V[j].X) I++;
			for(int k=j;k<=I;k++) {
				low[0][i][V[k].Y] = C;
			}
			j = I;
			C++;
		}
		reverse(V.begin(), V.end());
		C = 0;
		for(int j=0;j<(int)V.size();j++) {
			int I = j;
			while(I+1 < (int)V.size() && V[I+1].X == V[j].X) I++;
			for(int k=j;k<=I;k++) {
				hig[0][i][V[k].Y] = C;
			}
			j = I;
			C++;
		}
	}
	for(int i=1;i<=m;i++) {
		vector<pii> V;
		for(int j=1;j<=n;j++) {
			V.push_back({a[j][i], j});
		}
		sort(V.begin(), V.end());
		int C = 0;
		for(int j=0;j<(int)V.size();j++) {
			int I = j;
			while(I+1 < (int)V.size() && V[I+1].X == V[j].X) I++;
			for(int k=j;k<=I;k++) {
				low[1][V[k].Y][i] = C;
			}
			j = I;
			C++;
		}
		reverse(V.begin(), V.end());
		C = 0;
		for(int j=0;j<(int)V.size();j++) {
			int I = j;
			while(I+1 < (int)V.size() && V[I+1].X == V[j].X) I++;
			for(int k=j;k<=I;k++) {
				hig[1][V[k].Y][i] = C;
			}
			j = I;
			C++;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			printf("%d ", max(low[0][i][j], low[1][i][j]) + max(hig[0][i][j], hig[1][i][j]) + 1);
		}
		puts("");
	}
}