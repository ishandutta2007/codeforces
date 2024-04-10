#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<PII, int> P3I;
const int MAXN = (2 << 20) + 10;

//int T[MAXN << 2];
int n,m, nn;
P3I q[MAXN];
int a[MAXN], b[MAXN];
PII Q[MAXN];
int cnt;

void Nico(int l, int r, int p, int flag){
	if (p > cnt)
		return ;
	int del = Q[p].second - Q[p+1].second;
	if (Q[p].first == 2){
		Nico(l + del, r, p + 1, 1);
		for(int i = del; i >= 1; i--)
			printf("%d ",b[l + i - 1]);
	}
	else{
		Nico(l, r - del, p + 1, 1);
		for(int i = del; i >= 1; i--)
			printf("%d ", b[r - i + 1]);
	}
//	puts("");
}

void work(int l, int r, int p){
	cout<<l<<' '<<r<<' '<<p<<endl;
	if (p > m)
		return;
	int del = q[p+1].first.first - q[p].first.first;
	if (q[p].second == 2){
//		puts("##");
		work(l, r - del , p + 1);
		for(int i = del; i >= 1; i++)
			printf("%d ", b[l + i - 1]);
//		puts("@@");
	}
	else{
		work(l + del, r, p + 1);
	//	cout<<"##";
		for(int i = 0; i < del; i++)
			printf("%d ", b[l + i]);
	//	cout<<"##";
	}
}

int main(){
	cin>>n>>m;
//	for(nn = 1; nn < n + 2; nn <<= 1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	/*
	for(int i = 1; i <= 2 * nn - 1; i++)
		T[i] = 0;
	for(int i = 0; i <= n + 1; i++)
		f[i][0] = i - 1, f[i][1] = i + 1;
	for(int i = 1; i <= m; i++){
		scanf("%d%d", )
	}*/
/*	for(int i = 1; i <= m; i++){
		scanf("%d%d", &(q[i].second), &(q[i].first.first));
		q[i].first.second = -i;
		q[i].first.first *= -1;
	}
	sort(q + 1, q + m + 1);
	sort(b + 1, b - q[1].first.first + 1);
	q[m + 1] = P3I(PII(0, 0), 0);

	for(int i = 1; i <= m + 1; i ++){
		cout<<q[i].first.first<<' '<<q[i].first.second<<' '<<q[i].second<<endl;
	}
	puts("%%%%%%%%%%");

	work(1, -q[1].first.first, 1);
	for(int i = -q[1].first.first + 1; i <= n; i++)
		printf("%d ",a[i]);
	puts("");*/
	cnt = 0;
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		while(cnt && Q[cnt].second <= y)
			cnt--;
		Q[++cnt] = PII(x, y);
//		while(!Q.empty() && Q.top().second <= y)
//			Q.pop();
//		Q.push(PII(x, y));
//		scanf("%d%d", &(q[i].second), &(q[i].first.first));
//		q[i].first.second = -i;
//		q[i].first.first *= -1;
	}
	Q[cnt + 1] =PII(0, 0);
	sort(b + 1, b + Q[1].second + 1);
	Nico(1, Q[1].second, 1, 1);
	/*
	sort(q + 1, q + m + 1);
	q[m + 1] = P3I(PII(0, 0), 0);

	for(int i = 1; i <= m + 1; i ++){
		cout<<q[i].first.first<<' '<<q[i].first.second<<' '<<q[i].second<<endl;
	}
	puts("%%%%%%%%%%");

	work(1, -q[1].first.first, 1);
	*/
	for(int i = Q[1].second + 1; i <= n; i++)
		printf("%d ",a[i]);
	puts("");
	return 0;
}