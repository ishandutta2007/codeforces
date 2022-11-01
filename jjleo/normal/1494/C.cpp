#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, m, x;
vector<int> a, A, b, B;
int f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		a.clear(), A.clear(), b.clear(), B.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			if(x < 0) b.push_back(-x);
			else B.push_back(x);
		}
		for(int i = 1;i <= m;i++){
			scanf("%d", &x);
			if(x < 0) a.push_back(-x);
			else A.push_back(x);
		}
		reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
		int ans = 0, sum, x, l;
		for(int i = 0;i < a.size();i++) f[i] = 0;
		sum = x = l = 0;
		for(int i = 0;i < a.size();i++){
			while(x < b.size() && b[x] <= a[i]){
				sum++, x++;
			}
			while(l < i && a[i] - a[l] + 1 > sum) l++;
			f[i] = min(sum, i - l + 1);
		}
		x = (int)b.size() - 1, sum = 0;
		for(int i = (int)a.size() - 1;i >= 0;i--){
			while(x >= 0 && b[x] >= a[i]){
				if(b[x] == a[i]) sum++;
				x--;
			}
			if(i) f[i - 1] += sum;
		}
		for(int i = 0;i < a.size();i++) sum = max(sum, f[i]);
		ans += sum;
		swap(a, A), swap(b, B);
		for(int i = 0;i < a.size();i++) f[i] = 0;
		sum = x = l = 0;
		for(int i = 0;i < a.size();i++){
			while(x < b.size() && b[x] <= a[i]){
				sum++, x++;
			}
			while(l < i && a[i] - a[l] + 1 > sum) l++;
			f[i] = min(sum, i - l + 1);
		}
		x = (int)b.size() - 1, sum = 0;
		for(int i = (int)a.size() - 1;i >= 0;i--){
			while(x >= 0 && b[x] >= a[i]){
				if(b[x] == a[i]) sum++;
				x--;
			}
			if(i) f[i - 1] += sum;
		}
		for(int i = 0;i < a.size();i++) sum = max(sum, f[i]);
		ans += sum;
		printf("%d\n", ans);
	}
}