#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 3e6 + 10;

int n, m;

struct Pt{
//	int w, x, y, z;
	long long x, y, z;
};

Pt operator * (const Pt & a, const Pt & b){
	return (Pt){(a.x*b.x+a.y*b.y)%MM, (a.x*b.y+a.y*b.z)%MM, (a.y*b.y+a.z*b.z)%MM};
}

Pt operator + (const Pt & a, const Pt & b){
	return (Pt){(a.x + b.x) % MM, (a.y + b.y) % MM, (a.z + b.z) % MM};
}

bool operator == (const Pt & a, const Pt & b){
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator != (const Pt & a, const Pt & b){
	return a.x != b.x || a.y != b.y || a.z != b.z;
}

Pt tree[MAXN], lz[MAXN], tmp;
int M;

Pt Calc(int q){
	Pt ret = (Pt){0, 1, 1};
	Pt p = (Pt){0, 1, 1};
	for(q--; q; q>>=1){
		if (q & 1){
			ret = ret * p;
		}
		p = p * p;
	}
	return ret;
}

void Ps(Pt u){
	cout<<u.x<<' '<<u.y<<' '<<u.z<<endl;
}

Pt Un = (Pt){1, 0, 1};

void read(){
	scanf("%d%d", &n, &m);
	for(M = 1; M < n; M *= 2);
	for(int i = 1; i <= M * 2; i++)
		tree[i] = (Pt){0, 0, 0}, lz[i] = (Pt){1, 0, 1};
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		tree[M + i - 1] = Calc(x);
	}
	for(int i = M - 1; i >= 1; i--)
		tree[i] = tree[i<<1] + tree[(i<<1)|1];
}

void update(int u, int l, int r, int ll, int rr){
	if (l == ll && r == rr){
		lz[u] = lz[u] * tmp;
		return ;
	}
	if (lz[u] != Un){
		lz[u<<1] = lz[u<<1] * lz[u];
		lz[(u<<1)|1] = lz[(u<<1)|1] * lz[u];
		tree[u] = tree[u] * lz[u];
		lz[u] = Un;
	}
	int m = (l + r) / 2;
	if (rr <= m)
		update(u<<1, l, m, ll, rr);
	else
		if (ll > m)
			update((u<<1)|1, m+1, r, ll, rr);
		else
			update(u<<1, l, m, ll, m), update((u<<1)|1, m+1, r, m+1, rr);
	//lz[u] = lz[u] * tmp;
	tree[u] = tree[u << 1] * lz[u<<1] + tree[(u << 1) | 1] * lz[(u<<1)|1];
	//cout<<u<<' '<<l<<' '<<r<<' '<<tree[u].x<<' '<<tree[u].y<<' '<<tree[u].z<<' '<<lz[u].y<<endl;
}

Pt Query(int u, int l, int r, int ll, int rr){
	if (l == ll && r == rr)
		return tree[u] * lz[u];
	if (lz[u] != Un){
		lz[u<<1] = lz[u<<1] * lz[u];
		lz[(u<<1)|1] = lz[(u<<1)|1] * lz[u];
		tree[u] = tree[u] * lz[u];
		lz[u] = Un;
	}
	int m = (l + r) / 2;
	if (rr <= m)
		return Query(u<<1, l, m, ll, rr);
	else
		if (ll > m)
			return Query((u<<1)|1, m+1, r, ll, rr);
		else
			return Query(u<<1, l, m, ll, m) + Query((u<<1)|1, m+1, r, m+1, rr);
}

void solve(){
	for(int o = 1; o <= m; o++){
		int opt, l, r, x;
		scanf("%d%d%d", &opt, &l, &r);
		if (opt == 1){
			scanf("%d", &x);
			tmp = Calc(x);
		//	cout<<"tmp: ";Ps(tmp);
			update(1, 1, M, l, r);
		}
		else{
			printf("%lld\n", Query(1, 1, M, l, r).y);
		}
	}
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}