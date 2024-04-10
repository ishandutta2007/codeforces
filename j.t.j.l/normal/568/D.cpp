#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
typedef long long ll;

ll a[MAXN], b[MAXN], c[MAXN];
int ans[100][2];
int vis[MAXN];
int n, k;

int check(int p, int q, int r){	
	if (a[p] * b[q] - a[q] * b[p] == 0)
		return 0;
	if ((c[p] * b[q] - c[q] * b[p]) * a[r] + (a[p] * c[q] - a[q] * c[p]) * b[r] == (a[p] * b[q] - a[q] * b[p]) * c[r])
		return 1;
	else
		return 0;
}

void gen(int &p, int &q){
	p = rand()%n+1;
	q = rand()%n+1;
	while(vis[p])
		p = rand() % n + 1;
	while(vis[q] || p == q)
		q = rand() % n + 1;
}

int work(int p, int q){
	int tot = 0;
	for(int i = 1; i <= n; i++)
		if (!vis[i] && check(p, q, i))
			tot++;
	return tot;
}

int main(){
	srand(time(NULL));
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
		scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
	int flag = 0;
	int Nico = 10;
	for(int _ = 1; _ <= Nico && !flag; _++){
		for(int i = 1; i <= n; i++)
			vis[i] = 0;
		int cnt = n;
		for(int i = 1; i <= k; i++)
			ans[i][0] = ans[i][1] = 0;
		for(int i = 1; i <= k && cnt; i++){
			int p = rand() % n + 1, q = rand() % n + 1;
			if (cnt <= 1){
				int j = 0;
				for(int l = 1; l <= n; l++)
					if (!vis[l]){
						j = l;
						break;
					}
				cnt--;
				vis[j] = 1;
				ans[i][0] = j;
				ans[i][1] = -1;
			}
			else{
				gen(p, q);
				int r = 5 * k;
				while(work(p, q) < cnt / k - 8 && r > 0){
					gen(p, q);
					r--;
				}
				if (r <= 0)
					break;
				cnt -= 2;
				vis[p] = vis[q] = 1;
				ans[i][0] = p;
				ans[i][1] = q;
				for(int l = 1; l <= n; l++)
					if (!vis[l] && check(p, q, l)){
						vis[l] = 1;
						cnt--;
					}
			}
			/*
			if (cnt < n / 8.0){
				for(int l = 1; l <= n; l++)
					if (!vis[l]){
						j = l;
						break;
					}
			}
			else{
				j = rand() % n + 1;
				while(vis[j])
					j = rand() % n + 1;
			}
			cnt--;
			vis[j] = 1;
			if (cnt == 0){
				ans[i][0] = j;
				ans[i][1] = -1;
				break;
			}
			ans[i][0] = j;
			*/
		}
		if (cnt == 0){
			flag = 1;
			int j = 0;
			for(int l = 1; l <= k; l++)
				if (ans[l][0])
					j++;				
			puts("YES");
			cout<<j<<endl;
			for(int l = 1; l <= j; l++)
				cout<<ans[l][0]<<' '<<ans[l][1]<<endl;
			break;
		}
	}
	if (!flag)
		puts("NO");
	return 0;
}