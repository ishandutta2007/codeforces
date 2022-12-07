#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int sum[2];
int ans;
int S = maxn;
int x, y, z;
int a[maxn];

vector<int> v[3];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int X = 0;X <= 1;X++){
		for(int Y = 0;Y <= 1;Y++){
			a[0] = X + 100, a[n + 1] = Y + 100, ans = 0;
			for(int i = 0;i < 3;i++) v[i].clear();
			sum[0] = n / 2, sum[1] = (n + 1) / 2;
			int y = -1, z = 0;
			for(int i = 0;i <= n + 1;i++){
				x = a[i];
				if(x == 0 && a[i - 1]){
					y = i, z = a[i - 1] & 1;
				}
				if(x != 0){
					if(i == 0) continue;
					if(i >= 1 && i <= n) sum[x & 1]--;
					if(a[i - 1]){
						if(i != 1) ans += (a[i] - a[i - 1]) & 1;
						continue;
					}
					if(z == 0 && (x & 1) == 0) v[0].push_back(i - y);
					else if(z == 1 && (x & 1) == 1) v[1].push_back(i - y);
					else v[2].push_back(i - y);
				}
			}
			sort(v[0].begin(), v[0].end()), reverse(v[0].begin(), v[0].end());
			sort(v[1].begin(), v[1].end()), reverse(v[1].begin(), v[1].end());
			sort(v[2].begin(), v[2].end()), reverse(v[2].begin(), v[2].end());
			for(int i = (int)v[0].size() - 1;~i;i--){
				if(sum[0] >= v[0][i]) sum[0] -= v[0][i], v[0].pop_back();
				else break;
			}
			for(int i = (int)v[1].size() - 1;~i;i--){
				if(sum[1] >= v[1][i]) sum[1] -= v[1][i], v[1].pop_back();
				else break;
			}
			//printf("%d %d %d--\n", v[0].size(), v[1].size(), v[2].size());
			S = min(S, ans + (int)(v[0].size() + v[1].size()) * 2 + (int)v[2].size());
		}
	}
	printf("%d", S);
		
	//
	//printf("%d", ans + v[0].size() + v[1].size() + v[2].size() * 2);
	/*for(int i = n;i;i--) if(a[i] > 0) y = a[i] & 1, z = i;
	for(int i = 1;i <= n;i++){
		if(!a[i]){
			if(i == 1) x = sum[y] >= z - 1 ? y : (y ^ 1);
			if(sum[x]) a[i] = x, sum[x]--;
			else a[i] = x ^ 1, sum[x ^ 1]--;
		}else{
			x = a[i] & 1;
		}
		if(i > 1) ans += abs(a[i] - a[i - 1]) & 1;
	}*/
	//printf("%d", ans);
	
}