#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

vector<int> vec;
const int N = 1e5 +10;
void Add(int x){ if(vec.size() < N) vec.push_back(x);}
void Add(int l, int c){
	for(int i = 0; vec.size() < N && i < c; i++){
		for(int j = 0; j < l && vec.size() < N; j++) vec.push_back(vec[j]);
	}
}
ll L[N];
int type[N], l[N], c[N], x[N];
int m;
inline int query(long long pos){
	int i = lower_bound(L, L + m + 1, pos) - L;
	if(type[i] == 1) return x[i];
	return vec[(pos - L[i - 1] - 1) % l[i]];
}
int main(){
	sd(m);
	for(int i = 1; i <= m; i++){
		sd(type[i]);
		if(type[i] == 1){
			sd(x[i]);
			Add(x[i]);
			L[i] = L[i - 1] + 1;
		}
		else{
			sd(l[i]);
			sd(c[i]);
			Add(l[i], c[i]);
			L[i] = L[i - 1] + l[i] * c[i];
		}
	}
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		long long pos;
		scanf("%lld", &pos);
		printf("%d ", query(pos));	
	}
}