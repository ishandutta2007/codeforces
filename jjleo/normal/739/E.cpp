#include <bits/stdc++.h>
#define maxn 2005
using namespace std;

int n, a, b;

double p[maxn], q[maxn];

struct Data{
	double x;
	int y, z;
	
	Data(double a = 0, int b = 0, int c = 0){
		x = a, y = b, z = c;
	}
};

inline Data operator + (Data a, Data b){
	return Data(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline bool operator < (Data a, Data b){
	return fabs(a.x - b.x) > 1e-6 ? a.x < b.x : a.y ^ b.y ? a.y < b.y : a.z < b.z;
}

inline Data check(double x, double y){
	Data d;
	for(int i = 1;i <= n;i++){
		d = max(d, d + max(Data(p[i] - x, 1, 0), max(Data(q[i] - y, 0, 1), Data(p[i] + q[i] - p[i] * q[i] - x - y, 1, 1))));
	}
	//printf("%lf %lf %lf %d %d--\n", x, y, d.x, d.y, d.z);
	return d;
}

int main(){
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 1;i <= n;i++) scanf("%lf", &p[i]);
	for(int i = 1;i <= n;i++) scanf("%lf", &q[i]);
	double l = 0, r = 1, L, R, mid, Mid;
	while(r - l > 1e-8){
		mid = (l + r) / 2;
		L = 0, R = 1;
		while(R - L > 1e-8){
			Mid = (L + R) / 2;
			if(check(mid, Mid).z < b) R = Mid;
			else L = Mid;
		}
		if(check(mid, L).y < a) r = mid;
		else l = mid;
	}
	L = 0, R = 1;
	while(R - L > 1e-8){
		Mid = (L + R) / 2;
		if(check(l, Mid).z < b) R = Mid;
		else L = Mid;
	}
	printf("%.8lf", check(l, L).x + a * l + b * L);
}