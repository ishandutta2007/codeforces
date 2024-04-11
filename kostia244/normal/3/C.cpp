#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 5;
char mat[3][3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x = 0, o = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) {
			cin >> mat[i][j];
			if(mat[i][j]=='0')o++;
			if(mat[i][j]=='X')x++;
		}
	if(x!=o&&x!=o+1) {
		return cout << "illegal", 0;
	}
	int U = 0, V = 0;
	for(int i = 0; i < 3; i++) {
		if(mat[i][0]==mat[i][1]&&mat[i][1]==mat[i][2]&&mat[i][0]!='.') {
			if(mat[i][0]=='X') U++;
			else V++;
		}
		if(mat[0][i]==mat[1][i]&&mat[1][i]==mat[2][i]&&mat[0][i]!='.') {
			if(mat[0][i]=='X') U++;
			else V++;
		}
	}
	if(mat[0][0]==mat[1][1]&&mat[1][1]==mat[2][2]&&mat[0][0]!='.') {
		if(mat[0][0]=='X') U++;
				else V++;
	}
	if(mat[0][2]==mat[1][1]&&mat[1][1]==mat[2][0]&&mat[0][2]!='.') {
		if(mat[0][2]=='X') U++;
				else V++;
	}
	if(U&&V)
		return cout << "illegal", 0;
	if(V&&x>o)
		return cout << "illegal", 0;
	if(U&&x==o)
		return cout << "illegal", 0;
	if(U||V)
		return cout << "the " << (U?"first":"second") << " player won", 0;
	if(x+o==9) {
		return cout << "draw", 0;
	}
	cout << (x==o?"first":"second");
}