#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;


pii res[6];

bool go30(int a, int b){
	a -= 75;
	if (a < 0) return 0;

	if (a){
		b -= a;
		b -= 23;
		res[1] = {25 + a, 23 + a};
		if (b < 0) return 0;
		if (b <= 23 * 2){
			rep(i, 2, 3){
				res[i].fi = 25;
				res[i].se = (b > 23) ? 23 : b;
				b -= res[i].se;
			}
			return 1;
		}

	}
	else{
		if (b <= 23 * 3){
			rep(i, 1, 3){
				res[i].fi = 25;
				res[i].se = (b > 23) ? 23 : b;
				b -= res[i].se;
			}
			return 1;
		}
	}
	return 0;

}
bool go31(int a, int b){
	a -= 75; b -= 25;
	if (a < 0 || b < 0) return 0;
	if (a <= 23 && b <= 23 * 3){
		res[1] = {a, 25};
		rep(i, 2, 4){
			res[i].fi = 25;
			res[i].se = (b > 23) ? 23 : b;
			b -= res[i].se;
		}
		return 1;
	}
	rep(i, 1, a){
		int aa = a, bb = b;
		aa -= i; bb -= i;
		if (aa > 23 || bb > 23 * 3) continue;
		if (bb < 0) break;
		if (aa == 23){
			res[1] = {23 + i, 25 + i};


			rep(j, 2, 4){
				res[j].fi = 25;
				res[j].se = (bb > 23) ? 23 : bb;
				bb -= res[j].se;
			}
			return 1;

		}
		else{
			if (bb < 23) continue;
			res[1] = {aa, 25};
			res[2] = {25 + i, 23 + i};
			bb -= 23;
			rep(j, 3, 4){
				res[j].fi = 25;
				res[j].se = (bb > 23) ? 23 : bb;
				bb -= res[j].se;
			}
			return 1;
		}
	}
	return 0;
}
bool go32(int a, int b){
	a -= 65; b -= 50;
	if (a < 0 || b < 0) return 0;
	if (a <= 23 * 2 && b <= 23 * 2 + 13){
		rep(i, 1, 2){
			res[i].se = 25;
			res[i].fi = (a > 23) ? 23 : a;
			a -= res[i].fi;
		}
		rep(i, 3, 5){
			res[i].fi = i == 5 ? 15 : 25;
			res[i].se = (b > 23) ? 23 : b;
			b -= res[i].se;
		}
		return 1;
	}
	int aa = a, bb = b;
	rep(t, 1, aa){
		a = aa - t; b = bb - t;
		if (a > 23 * 2 || b > 23 * 2 + 13) continue;
		if (b < 0) break;
		if (a >= 23){
			res[1] = {23 + t, 25 + t};
			res[2] = {a - 23, 25};
			rep(i, 3, 5){
				res[i].fi = i == 5 ? 15 : 25;
				res[i].se = (b > 23) ? 23 : b;
				b -= res[i].se;
			}
			return 1;
		}
		else{
			if (b < 13) continue;
			b -= 13;
			res[5] = {15 + t, 13 + t};
			rep(i, 1, 2){
				res[i].se = 25;
				res[i].fi = (a > 23) ? 23 : a;
				a -= res[i].fi;
			}
			rep(i, 3, 4){
				res[i].fi = i == 5 ? 15 : 25;
				res[i].se = (b > 23) ? 23 : b;
				b -= res[i].se;
			}
			return 1;
		}
	}
	return 0;

}
int main(){
#ifdef local
	freopen("read.txt", "r", stdin);
#endif // local
	int n, a, b;
	scanf("%d", &n);
	rep(i, 1, n){
		scanf("%d%d", &a, &b);
		if (go30(a, b)){
			printf("3:0\n");
			rep(i, 1, 3)
				printf("%d:%d%c", res[i].fi, res[i].se, i == 3 ? '\n' : ' ');
		}
		else if (go31(a, b)){
			printf("3:1\n");
			rep(i, 1, 4)
				printf("%d:%d%c", res[i].fi, res[i].se, i == 4 ? '\n' : ' ');
		}
		else if (go32(a, b)){
			printf("3:2\n");
			rep(i, 1, 5)
				printf("%d:%d%c", res[i].fi, res[i].se, i == 5 ? '\n' : ' ');
		}
		else if (go32(b, a)){
			printf("2:3\n");
			rep(i, 1, 5)
				printf("%d:%d%c", res[i].se, res[i].fi, i == 5 ? '\n' : ' ');
		}
		else if (go31(b, a)){
			printf("1:3\n");
			rep(i, 1, 4)
				printf("%d:%d%c", res[i].se, res[i].fi, i == 4 ? '\n' : ' ');

		}
		else if (go30(b, a)){
			printf("0:3\n");
			rep(i, 1, 3)
				printf("%d:%d%c", res[i].se, res[i].fi, i == 3 ? '\n' : ' ');

		}
		else printf("Impossible\n");
	}
    return 0;
}