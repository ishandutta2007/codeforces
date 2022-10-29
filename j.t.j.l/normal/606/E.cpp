#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1e5 + 10;

PII a[MAXN];
int n, p, q;
double ans = 1e20;

int sgn(long long x){
	if (x == 0)
		return 0;
	if (x < 0)
		return -1;
	else
		return 1;
}

long long cross(int p, int q, int r){
	return (long long)(a[q].first - a[p].first) * (-a[r].second + a[p].second) - (long long)(a[r].first - a[p].first) * (-a[q].second + a[p].second);
}

int dir(int p, int q){
	return sgn(cross(n+1, p, q));
}

void work(int x, int y){
	long long ax = a[x].first, bx = -a[x].second, ay = a[y].first, by = -a[y].second;
	ans = min(ans, ((double)p * by - q * ay + q * ax - p * bx) / (ax * by - ay * bx));
}

int main(){
	cin>>n>>p>>q;
	a[0] = PII(p, -q);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a[i].first, &a[i].second);
		a[i].second = -a[i].second;
	}
	a[n+1] = PII(0,0);
	sort(a+1, a+n+1);
	vector<int> Q;
	for(int i = 1; i <= n; i++){
		if (Q.size() < 2)
			Q.push_back(i);
		else{
			while(Q.size() >= 2 && cross(Q[Q.size()-1], Q[Q.size()-2], i) <= 0)
				Q.pop_back();
			Q.push_back(i);
		}
	}
	//int flag = 1;
	for (int i = 1; i < Q.size(); i++){
		if (dir(Q[i-1], 0) != dir(Q[i], 0)){
			work(Q[i-1], Q[i]);
		//	flag = 0;
		//	break;
		}
	}
	//if (flag){
	//	double ans = 1e20;
		for(int i = 1; i <= n; i++)
			ans = min(ans, max((double)p / a[i].first, (double)q / -a[i].second));
		printf("%.10lf\n", ans);
	//}
	return 0;
}