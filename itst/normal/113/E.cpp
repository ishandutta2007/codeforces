#include<bits/stdc++.h>
using namespace std;

#define int long long
int T , N , M , S , N1 , M1 , N2 , M2 , ans;
int up(int x){return log10(10 * x - 5);}

int calc(int l , int r , int num){
	if(r < l) return 0;
	if(num <= 0) return r - l + 1;
	int now = pow(10 , num);
	if(r % now != now - 1) r = r - r % now - 1;
	l = l + (now - 1) - l % now;
	return (r - l) / now + 1;
}

int diff(int P , int Q){
	int sum = 0;
	while(P || Q){sum += P % 10 != Q % 10; P /= 10; Q /= 10;}
	return sum;
}

signed main(){
	cin >> N >> M >> S >> N1 >> M1 >> N2 >> M2;
    if(up(M) + up(N) < S){puts("0"); return 0;}
	if(N1 == N2 && M1 == M2){puts("0"); return 0;}
	M2 == 0 ? N2 = (N2 + N - 1) % N , M2 = M - 1 : --M2;
	if(S <= 1) ans = N1 == N2 && M2 >= M1 ? M2 - M1 + 1 : M - M1 + M2 + 1 + (N + N2 - N1 - 1) % N * M;
	else if(N1 == N2 && M1 <= M2) ans = M2 == M - 1 ? calc(M1 , M2 - 1 , S - 1) + (diff(M - 1 , 0) + diff(N1 , (N1 + 1) % N) >= S) : calc(M1 , M2 , S - 1);
	else{
		int len = N2 <= N1 ? N + N2 - N1 - 1 : N2 - N1 - 1;
		ans += calc(M1 , M - 2 , S - 1);
		M2 == M - 1 ? (++len , N2 = (N2 + 1) % N) : ans += calc(0 , M2 , S - 1);
		ans += calc(0 , M - 2 , S - 1) * len; int val = diff(M - 1 , 0);
		ans += N2 > N1 ? calc(N1 , N2 - 1 , S - val - 1) :
			calc(N1 , N - 2 , S - val - 1) + calc(0 , N2 - 1 , S - val - 1) + (diff(N - 1 , 0) + val >= S);
	}
	cout << ans; return 0;
}