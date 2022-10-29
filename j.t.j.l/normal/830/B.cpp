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

class BITree{
public:
    static const int SIZE = 100010, BIAS = 5;
    long long u[SIZE];
    void clear(){
        memset(u,0,sizeof(u));
    }
    void modify(int x, long long v){
        for(x+=BIAS;x<SIZE;x+=x&-x) u[x]+=v;
    }
    long long getsum(int x){
        long long s=0;
        for(x+=BIAS;x;x-=x&-x) s+=u[x];
        return s;
    }
	long long query(int l, int r){
		return (r - l + 1) - (getsum(r) - getsum(l - 1));
	}
} nico;

int a[MAXN];
vector<int> E[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		E[a[i]].push_back(i);
	}
	ll ans = 0;
	int pos = 0;
	nico.clear();
	for (int i = 1; i <= 100000; i++) if (E[i].size()){
		int p = 0, q = E[i].size() - 1;
		int r = -1;
		while(r < q && E[i][r + 1] < pos)
			r++;
		// [r + 1, q]
		// [p, r]
		if (p <= r) {
			ans += nico.query(pos + 1, n);
			ans += nico.query(1, E[i][r]);
			pos = E[i][r];
			for (auto &x : E[i])
				nico.modify(x, 1);
		}
		else{
			ans += nico.query(pos + 1, E[i][q]);
			pos = E[i][q];
			for (auto &x : E[i])
				nico.modify(x, 1);
		}
	}
	printf("%lld\n", ans);
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