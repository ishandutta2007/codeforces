#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, a[122][5];
int mode[5];
int solver[5];

int solve(){
	int stp = 0, edp = 2e9;
	for(int i=0; i<5; i++){
		if(a[0][i] == -1){
			stp = max(stp, (solver[i] << (mode[i] - 1)) - n);
			if(mode[i] != 6) edp = min(edp, (solver[i] << mode[i]) - n - 1);
		}
	}
	int ret = 2e9;
	for(int i=0; i<32; i++){
		lint tmp = 0;
		for(int j=0; j<5; j++){
			if(a[0][j] == -1) continue;
			auto trial = [&](lint U){
				lint st = (n + U + (1 << mode[j]) - 1) >> mode[j];
				lint ed = (n + U) >> (mode[j] - 1);
				if(mode[j] == 6) st = 0;
				st -= solver[j];
				ed -= solver[j];
				st = max(st, 0ll);
				ed = min(ed, U);
				return st <= ed;
			};
			int s = (stp - i + 31) / 32, e = (edp - i + 32) / 32 - 1;
			if(s > e){
				tmp = 1e18;
				continue;
			}
			while(s != e){
				int m = (s+e)/2;
				if(trial(32ll * m + i)) e = m;
				else s = m+1;
			}
			if(trial(32ll * s + i)) tmp = max(tmp, 32ll * s + i);
			else tmp = 1e18;
		}
		ret = (int)min(1ll * ret, tmp);
	}
	return ret;
}

int ret = 2e9;

void bktk(int x){
	if(x == 5){
		int scVasya = 0;
		int scPetya = 0;
		for(int i=0; i<5; i++){
			if(a[0][i] != -1){
				scVasya += (mode[i] * 2) * (250 - a[0][i]); 
			}
			if(a[1][i] != -1){
				scPetya += (mode[i] * 2) * (250 - a[1][i]);
			}
		}
		if(scVasya > scPetya){
			ret = min(ret, solve());
		}
	}
	else{
		for(mode[x] = 1; mode[x] <= 6; mode[x]++) bktk(x+1);
	}
}


int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++){
			cin >> a[i][j];
			if(a[i][j] != -1) solver[j]++;
		}
	}
	bktk(0);
	if(ret > 1e9) ret = -1;
	cout << ret;
}