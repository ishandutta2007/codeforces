#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n;
lint a[505][505], vx, vy;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j] == 0){
				vx = i, vy = j;
			}
		}
	}
	if(n == 1){
		puts("42");
		return 0;
	}
	int naver = (vx ? (vx-1) : (vx+1));
	lint s1 = 0, s2 = 0;
	for(int i=0; i<n; i++){
		s1 += a[naver][i];
		s2 += a[vx][i];
	}
	a[vx][vy] = s1 - s2;
	if(s1 - s2 <= 0){
		puts("-1");
		return 0;
	}
	for(int i=0; i<n; i++){
		lint t1 = 0, t2 = 0, t3 = 0, t4 = 0;
		for(int j=0; j<n; j++){
			t1 += a[i][j];
			t2 += a[j][i];
			t3 += a[j][j];
			t4 += a[j][n-j-1];
		}
		if(t1 != s1 || t2 != s1 || t3 != s1 || t4 != s1){
			puts("-1");
			return 0;
		}
	}
	printf("%lld\n", a[vx][vy]);
}