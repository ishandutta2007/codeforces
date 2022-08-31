#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

vector<int> getL(vector<int> p){
	int n = p.size();
	vector<int> L(n);
	L[0] = 0;
	for(int i = 1; i < n; i++){
		L[i] = p[i - 1] < p[i] ? L[i - 1] + 1 : 0;
	}
	return L;
}

vector<int> getR(vector<int> p){
	int n = p.size();
	vector<int> R(n);
	R[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--){
		R[i] = p[i + 1] < p[i] ? R[i + 1] + 1 : 0;
	}
	return R;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	vector<int> p(n);
	for(int & x : p){
		cin >> x;
		x--;
	}
	vector<int> q(n);
	
	for(int i = 0; i < n; i++) q[i] = -p[i];

	vector<int> L1 = getL(p), R1 = getR(p);
	vector<int> L2 = getL(q), R2 = getR(q);

	vector<int> prefix(n + 1, 0), suffix(n + 1, 0);
	vector<int> H(n + 1, 0), R(n + 1, 0);

	int P = -1, P2 = -1;
	for(int i = 0; i < n; i++){
		P = max(P, max(L2[i], R2[i]));
		P2 = max(P2, L2[i]);
		prefix[i] = P;
		H[i] = P2;
	}

	for(int i = n - 1; i >= 0; i--){
		suffix[i] = max(suffix[i + 1], max(L2[i], R2[i]));
		R[i] = max(R[i + 1], R2[i]);
	}
	
	int num = 0;
	for(int x = 0; x < n; x++){
		if(L1[x] != R1[x] || L1[x] % 2 == 1) continue;
		int a = L1[x];
		int u = x - a, v = x + a;
		int Z = max(u == 0 ? 0 : prefix[u - 1], suffix[v + 1]);
		num += Z < a && R[x + 1] < a && (x==0?0:H[x - 1]) < a;
	}
	cout << num << endl;
}