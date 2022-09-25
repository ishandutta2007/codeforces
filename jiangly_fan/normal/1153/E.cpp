#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200;
int a[maxn], b[maxn], tot;
int q(int aa, int bb, int cc, int dd){
	assert(++ tot <= 2019);
	cout << "? " << aa << " " << bb << " " << cc << " " << dd << endl;
	int res;
	cin >> res;
	return res;
}
void ans(int aa, int bb, int cc, int dd){
	int res = q(aa, cc, aa, cc);
	if(res & 1)
	cout << "! " << aa << " " << cc << " " << bb << " " << dd << endl;
	else
	cout << "! " << aa << " " << dd << " " << bb << " " << cc << endl;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i += 1) a[i] = q(1, 1, n, i);
	for(int i = 1; i < n; i += 1) b[i] = q(1, 1, i, n);
	int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
	for(int i = 1; i <= n; i += 1){
		if(b[i] % 2 and (i == 1 or b[i - 1] % 2 == 0)) a1 = i;
		if(b[i] % 2 == 0 and b[i - 1] % 2) a2 = i;
	}
	
	for(int i = 1; i <= n; i += 1){
		if(a[i] % 2 and (i == 1 or a[i - 1] % 2 == 0)) b1 = i;
		if(a[i] % 2 == 0 and a[i - 1] % 2) b2 = i;
	}
	if(a1) assert(a1 < a2);
	if(b1) assert(b1 < b2);
	if(a1 and b1 and a2 and b2);
	else{
		if(a1 and a2){
			int L = 1, R = n;
			while(L != R){
				int M = (L + R) >> 1, res = q(1, 1, a1, M);
				if(res & 1) R = M;
				else L = M + 1;
			}
			b1 = b2 = L;
		}
		else if(b1 and b2){
			int L = 1, R = n;
			while(L != R){
				int M = (L + R) >> 1, res = q(1, 1, M, b1);
				if(res & 1) R = M;
				else L = M + 1;
			}
			a1 = a2 = L;
		}
		else{
			while(true);
		}
	}
	ans(a1, a2, b1, b2);
}