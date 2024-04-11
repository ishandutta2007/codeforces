#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m;
int a[22][22];
int bk[22];

bool doop(int a1, int a2, int b1, int b2, vector<int> v){
	swap(v[a1], v[a2]);
	swap(v[b1], v[b2]);
	for(int i=0; i<m; i++){
		if(v[i] != i) return 0;
	}
	return 1;
}

int ok(int p, int q){
	for(int i=0; i<n; i++){
		vector<int> v;
		for(int j=0; j<m; j++){
			v.push_back(a[i][j]);
		}
		bool ok = 0;
		if(doop(0, 0, p, q, v)) ok = 1;
		if(doop(p, q, 0, 0, v)) ok = 1;
		for(int j=0; j<m; j++){
			for(int k=j+1; k<m; k++){
				if(doop(j, k, p, q, v)) ok = 1;
				if(doop(p, q, j, k, v)) ok = 1;
			}
		}
		if(!ok) return 0;
	}
	return 1;
}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	if(ok(0, 0)){
		puts("YES");
		return 0;
	}
	for(int i=0; i<m; i++){
		for(int j=i+1; j<m; j++){
			if(ok(i, j)){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
}