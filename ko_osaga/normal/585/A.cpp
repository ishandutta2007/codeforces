#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 200005;

int n;
lint a[MAXN], b[MAXN], c[MAXN];
int proc[MAXN];

void boom(int x){
	proc[x] = 1;
	for(int i=x+1; i<=n; i++){
		if(!proc[i]) c[i] -= b[x];
	}
	for(int i=x+1; i<=n; i++){
		if(!proc[i] && c[i] < 0) boom(i);
	}
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i] >> b[i] >> c[i];
	for(int i=1; i<=n; i++){
		if(proc[i]) continue;
		int que = a[i];
		vector<int> v;
		for(int j=i+1; j<=n; j++){
			if(proc[j]) continue;
			c[j] -= que;
			if(c[j] < 0) v.push_back(j);
			que--;
			if(que == 0) break;
		}
		if(!v.empty()) boom(v[0]);
	}
	printf("%d\n", count(proc + 1, proc + n + 1, 0));
	for(int i=1; i<=n; i++) if(!proc[i]) printf("%d ", i);
}