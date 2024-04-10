#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define eps 1e-8
const int _ = 2e5 + 7; const ld pi = acos(-1);
long long pos[_][2] , jump[_][20] , logg2[_] , N , M; ld st[20][_];

ld qry(int l , int r){int t = logg2[r - l + 1]; return min(st[t][l] , st[t][r - (1 << t) + 1]);}

bool check(ld now){
#define PLL pair < ld , ld >
	vector < PLL > tmp;
	for(int i = 1 ; i <= N ; ++i){
		ld ag = atan2(pos[i][1] , pos[i][0]) , ang = acos(now / sqrt(pos[i][0] * pos[i][0] + pos[i][1] * pos[i][1]));
		if(ag - ang < -pi) ag += 2 * pi;
		tmp.push_back(PLL(ag - ang , ag + ang)); tmp.push_back(PLL(ag - ang + 2 * pi , ag + ang + 2 * pi));
	}
	sort(tmp.begin() , tmp.end());
	
	for(int i = 0 ; i < 2 * N ; ++i) st[0][i] = tmp[i].second;
	for(int i = 1 ; 1 << i <= 2 * N ; ++i)
		for(int j = 0 ; j + (1 << i) - 1 < 2 * N ; ++j)
			st[i][j] = min(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);

	jump[2 * N][0] = 2 * N;
	for(int i = 0 ; i < 2 * N ; ++i){
		int L = i , R = min(2 * N - 1 , i + N - 1);
		while(L < R){int mid = (L + R + 1) >> 1; qry(i , mid) >= tmp[mid].first ? L = mid : R = mid - 1;}
		jump[i][0] = L + 1;
	}

	for(int i = 2 * N ; i >= 0 ; --i) for(int j = 1 ; 1 << j <= M ; ++j) jump[i][j] = jump[jump[i][j - 1]][j - 1];

	for(int i = 0 ; i < N ; ++i){
		int pos = i;
		for(int j = 0 ; 1 << j <= M && pos < N + i ; ++j) if(M >> j & 1) pos = jump[pos][j];
		if(pos >= N + i) return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M; ld L = 0 , R = 1e9; logg2[0] = -1;
	for(int i = 1 ; i <= 2 * N ; ++i) logg2[i] = logg2[i >> 1] + 1;
	for(int i = 1 ; i <= N ; ++i){cin >> pos[i][0] >> pos[i][1]; R = min(R , (ld)sqrt(pos[i][0] * pos[i][0] + pos[i][1] * pos[i][1]));}
	while(R - L > eps){ld mid = (L + R) / 2; check(mid) ? L = mid : R = mid;}
	cout << fixed << setprecision(9) << L; return 0;
}