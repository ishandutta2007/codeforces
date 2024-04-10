#include<bits/stdc++.h>

using namespace std;

const int Umi = 1048576 << 1;

struct Nico{
	int l, r, i;
};

bool operator < (const Nico & a, const Nico&b){
	return a.r < b.r;
}

int a[Umi];
Nico Q[Umi];
vector<Nico> E[1030];
int num[Umi];
long long  ans[Umi];

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 2; i <= n; i++)
		a[i] = a[i] ^ a[i-1];
//	for(int i = 1; i <= n; i++)
//		cout<<a[i]<<' '; cout<<endl;
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &Q[i].l, &Q[i].r);
		Q[i].l--;
		Q[i].i = i;
	}
	int x = n / (int)(sqrt(n)) + 1;
	int y = sqrt(n);
	for(int i = 0; i < x; i++)
		E[i].clear();
	for(int i = 1; i <= m; i++){
		E[Q[i].l / y].push_back(Q[i]);
	}
	for(int i = 0; i < x; i++)
		sort(E[i].begin(), E[i].end());
	for(int i = 0; i < Umi; i++){
		num[i] = 0;	
	}	
	int L = 0, R = 0;
	long long now = 0; num[0] = 1;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < E[i].size(); j++){
			Nico w = E[i][j];
	//		cout<<w.l<<' '<<w.r<<' '<<w.i<<endl;
	//		cout<<now<<endl;
			while(R < w.r){
				R++;
				now += num[k ^ a[R]];
				num[a[R]]++;	
			}
			while(R > w.r){
				num[a[R]]--;
				now -= num[k ^ a[R]];
				R--;
			}
			while(L < w.l){
				num[a[L]]--;
				now -= num[k ^ a[L]];
				L++;
			}
			while(L > w.l){
				L--;
				now += num[k ^ a[L]];
				num[a[L]]++;
			}
		/*	cout<<now<<endl;
			
			for(int i = 0; i <= 10; i ++)
				cout<<num[i]<<' '; cout<<endl;
		*/	ans[w.i] = now;
		}
	}
	for(int i = 1; i <= m; i++)
		printf("%lld\n", ans[i]);
	return 0;
}