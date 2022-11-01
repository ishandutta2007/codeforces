#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); int N , DX1 , DY1 , DX2 , DY2;
	cin >> N >> DX1 >> DY1 >> DX2 >> DY2; if(DX1 < 0){DX1 = -DX1; DY1 = -DY1;} if(DX2 < 0){DX2 = -DX2; DY2 = -DY2;}
	if(!DX1 && !DX2){puts("NO"); return 0;}
	int DX = __gcd(DX1 , DX2); long long DY = llabs(1ll * DX2 / DX * DY1 - 1ll * DX1 / DX * DY2);
	if(DX * DY == N){
		cout << "YES" << endl;
		for(int i = 0 ; i < DX ; ++i) for(int j = 0 ; j < DY ; ++j) cout << i << ' ' << j << '\n';
	}else cout << "NO" << endl;
	return 0;
}