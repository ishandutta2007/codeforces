#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
const int mod = 1e9 + 7;
const int MAXN = 500005;

int n; string s;
int sum[MAXN];
int dap = -1, sx, sy;

void flush(){
	printf("%d\n%d %d\n", dap, sx, sy);
	exit(0);
}

void Do(int x, int y){
	swap(s[x], s[y]);
	for(int i=0; i<n; i++){
		sum[i+1] = sum[i];
		if(s[i] == '(') sum[i+1]++;
		else sum[i+1]--;
	}
	int minv = *min_element(sum, sum + n);
	int cnt = count(sum, sum + n, minv);
	if(dap < cnt){
		dap = cnt;
		sx = x + 1;
		sy = y + 1;
	}
	swap(s[x], s[y]);
	for(int i=0; i<n; i++){
		sum[i+1] = sum[i];
		if(s[i] == '(') sum[i+1]++;
		else sum[i+1]--;
	}
}

int main(){
	cin >> n >> s;
	for(int i=0; i<n; i++){
		sum[i+1] = sum[i];
		if(s[i] == '(') sum[i+1]++;
		else sum[i+1]--;
	}
	if(sum[n] != 0){
		puts("0\n1 1");
		return 0;
	}
	int minv = *min_element(sum, sum + n);
	Do(0, 0);
	if(count(sum, sum + n, minv) == n / 2){
		flush();
		return 0;
	}
	vector<int> v;
	int cur= -1;
	int st = 69, ed = 69;
	for(int i=0; i<n; i++){
		if(sum[i] == minv){
			for(int j=0; j<n; j++){
				if(sum[(i+j)%n] >= minv + 2){
					int l = j;
					int cost = 0;
					while(l < n && sum[(i+l)%n] >= minv + 2){
						if(sum[(i+l)%n] == minv + 2) cost++;
						l++;
					}
					if(cost > cur){
						cur = cost;
						st = i + j;
						ed = i + l;
					}
					j = l;
				}
			}
			break;
		}
	}
	assert(cur >= 0);
	st += n - 1;
	ed += n - 1;
	Do(st % n, ed % n);
	cur = -1;
	st = 69, ed = 69;
	for(int i=0; i<n; i++){
		if(sum[i] == minv){
			for(int j=0; j<n; j++){
				if(sum[(i+j)%n] >= minv + 1){
					int l = j;
					int cost = 0;
					while(l < n && sum[(i+l)%n] >= minv + 1){
						if(sum[(i+l)%n] == minv + 1) cost++;
						l++;
					}
					if(cost > cur){
						cur = cost;
						st = i + j;
						ed = i + l;
					}
					j = l;
				}
			}
			break;
		}
	}
	assert(cur >= 0);
	st += n - 1;
	ed += n - 1;
	Do(st % n, ed % n);
		flush();
}