#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>

const int N = 1e6 + 10;
int A[N];
struct PT{
	int a, b, c, d, e;
};
PT pts[1005];
int dot(const PT & p1, const PT & p2){
	return p1.a * p2.a + p1.b * p2.b + p1.c * p2.c + p1.d * p2.d + p1.e * p2.e;
}
int main(){
	int n, t;
	sd(n);
	for(int i = 1; i <= n; i++) cin >> pts[i].a >> pts[i].b >> pts[i].c >> pts[i].d >> pts[i].e;
	if(n > 100){
		printf("%d\n", 0);
		return 0;
		for(int i = 1; i <= n; i++) printf("%d\n", i);
		return 0;
	}
	int k = 0;
	vector<int> vec;
	for(int i = 1; i <= n; i++){
		bool flag = 0;
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++){
				if(i != j && i != k && j != k){
					PT p1, p2;
					p1.a = pts[j].a - pts[i].a;
					p1.b = pts[j].b - pts[i].b;
					p1.c = pts[j].c - pts[i].c;
					p1.d = pts[j].d - pts[i].d;
					p1.e = pts[j].e - pts[i].e;
					p2.a = pts[k].a - pts[i].a;
					p2.b = pts[k].b - pts[i].b;
					p2.c = pts[k].c - pts[i].c;
					p2.d = pts[k].d - pts[i].d;
					p2.e = pts[k].e - pts[i].e;

					int dt = dot(p1, p2);
					if(dt > 0){
						flag = 1;
					}
				}
			}
		if(!flag){
			vec.pb(i);
		}	
	}
	printf("%d\n", (int)vec.size());
	for(int x : vec) printf("%d\n", x);
}