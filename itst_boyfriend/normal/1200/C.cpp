#include<bits/stdc++.h>
using namespace std;

int main(){
	#define int long long
	int T , N , M , L;
	cin >> N >> M >> T;
	L = __gcd(N , M);
	while(T--){
		int A , B , C , D; cin >> A >> B >> C >> D;
		--B; --D;
		B = B / (A == 1 ? N / L : M / L);
		D = D / (C == 1 ? N / L : M / L);
		puts(B == D ? "YES" : "NO");
	}
	return 0;
}