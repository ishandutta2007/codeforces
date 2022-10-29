#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int a[MAXN], b[MAXN];

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int x = sqrt(n);
	int y = n / x;
	for(int i = 0; i <= y; i++){
		int flag = 1;
		for(int j = i * x + 1; j < (i + 1) * x && j < n; j++)
			if (a[j] != a[j-1]){
				flag = 0;
				break;
			}
		b[i] = flag;
	}
	for(int o = 1; o <= m; o++){
		int l, r, w;
		scanf("%d%d%d", &l, &r, &w);
		int p = l / x, q = r / x;
		if (p == q){
			int flag = -1;
			for(int i = l; i <= r; i++)
				if (a[i] != w){
					flag = i;
					break;
				}
			printf("%d\n", flag);
		}
		else{
			int flag = -1;
			for(int i = l; i < (p + 1) * x && i < n; i++)
				if (a[i] != w){
					flag = i;
					break;
				}
			if (flag == -1){
				for(int i = q * x; i <= r; i++)
					if (a[i] != w){
						flag = i;
						break;
					}
			}
			if (flag == -1){
				for(int i = p+1; i <= q - 1; i++){
					if (b[i]){
						if (a[i * x] != w){
							flag = i * x;
							break;
						}
					}
					else{
						for(int j = i * x; j < (i + 1) * x; j++)
							if (a[j] != w){
								flag = j;
								break;
							}
					}
				}
			}
			printf("%d\n", flag);
		}
	}
	return 0;
}