#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

struct tap{
	ll v, t;
} a[MAXN];

ll T;

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%lld", &n, &T);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i].v);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i].t);
	sort(a + 1, a + n + 1, [](const tap & a, const tap & b){
		return a.t < b.t;
	});
	if (a[1].t > T || a[n].t < T){
		puts("0");
		return ;
	}
	double l = 0, r = 0;
	for (int i = 1; i <= n; i++)
		r += a[i].v;
	
	//for (int i = 1; i <= n; i++)
	//	cout << a[i].v << ' ' << a[i].t << endl;
	
	for (int p = 1; p <= 100; p++){
		double m = (l + r) / 2;
		double mn = 0, mx = 0;
		double now = m;
		for (int i = 1; i <= n; i++)
			if (now >= a[i].v){
				mn += a[i].v * a[i].t;
				now -= a[i].v;
			}
			else{
				mn += now * a[i].t;
				now = 0;
				break;
			}
		now = m;
		for (int i = n; i >= 1; i--)
			if (now >= a[i].v){
				mx += a[i].v * a[i].t;
				now -= a[i].v;
			}
			else{
				mx += now * a[i].t;
				now = 0;
				break;
			}
		//cout << m << ' ' << mn << ' ' << mx << ' ' << T * m << endl;
		if (mn <= T * m && T * m <= mx)
			l = m;
		else
			r = m;
	}
	printf("%.15f\n", (l + r) / 2);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}