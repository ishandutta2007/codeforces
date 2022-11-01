#include <bits/stdc++.h>
#define maxn 10000086

using namespace std;

int n;
unordered_set<int> st[400][6086];
tuple<int, int, int, int, int> t[maxn];
vector<int> v[50];
int cnt = 1;
double x, y;

void print(int x){
	if(x == 1) return;
	printf("("), print(get<3>(t[x])), printf(")"), print(get<4>(t[x]));
}

int main(){
	scanf("%d", &n);
	v[0].push_back(1), st[0][0].insert(0), t[1] = make_tuple(0, 0, 0, 0, 0);
	int mx = 0;
	for(int i = 2;i <= n;i += 2){
	    for(int j = 0;j <= 350;j++) for(int k = 0;k <= 6000;k++) st[j][k].clear();
		for(int j = 0;j * 2 <= i - 2;j++){
			for(int k = 0;k < v[j * 2].size();k++){
				for(int l = 0;l < v[i - j * 2 - 2].size();l++){
					int idl = v[j * 2][k], idr = v[i - j * 2 - 2][l];
					int ml = get<0>(t[idl]), xml = get<1>(t[idl]), ym3l = get<2>(t[idl]);
					int mr = get<0>(t[idr]), xmr = get<1>(t[idr]), ym3r = get<2>(t[idr]);
					int m = ml + mr + 2 * j + 1;
					int xm = xml + ml + xmr + (2 * j + 2) * mr + (j + 1) * (2 * j + 1);
					int ym3 = ym3l + 3 * ml + ym3r + 3 * j + 1;
					if(st[m][xm].find(ym3) != st[m][xm].end()) continue;
					mx = max({mx, m});
					v[i].push_back(++cnt), st[m][xm].insert(ym3), t[cnt] = make_tuple(m, xm, ym3, idl, idr);
				}
			}
		}
	}
	scanf("%lf%lf", &x, &y);
	for(int i = 0;i < v[n].size();i++){
		int id = v[n][i], m = get<0>(t[id]), xm = get<1>(t[id]), ym3 = get<2>(t[id]);
		if(fabs(x - 1.0 * xm / m) < 1e-7 && fabs(y - 1.0 * ym3 / m / 3) < 1e-7){
			print(id);
			return 0;
		}
	}
}