#include<bits/stdc++.h>
using namespace std;

long long N , A , B; long long ans;
long long binom(long long a , long long b , bool f = 1){
	if(a < b || b < 0) return 0;
	if(a - b < b) b = a - b;
	long double val = 1; for(int i = 1 ; i <= b ; ++i) val = val * (a - i + 1) / i;
	if(f && val > 5e15) return 1e15;
	long long vl = 1; for(int i = 1 ; i <= b ; ++i) vl = vl * (a - i + 1) / i;
	return vl;
}
bool check(long long mid){
	long long sum = 0; for(int i = 0 ; i <= 2e6 && i * B <= mid && sum < N ; ++i) sum += binom((mid - B * i) / A + 1 + i , 1 + i);
	return sum >= N;
}

int main(){
	cin >> N >> A >> B; if(A > B){swap(A , B);} if(!--N){puts("0"); return 0;}
	if(!A){ans = (long long)N * B;}
	else{
		long long L = 0 , R = 1e18; while(L < R){long long mid = (L + R) >> 1; check(mid) ? R = mid : L = mid + 1;}
		ans = (long long)N * (A + B); --L;
		for(int i = 0 ; i <= 2e6 && i * B <= L ; ++i){
			long long p = (L - B * i) / A; N -= binom(p + 1 + i , 1 + i);
			ans += (long long)binom(p + 1 + i , 1 + i , 0) * B * i + (long long)binom(p + 1 + i , 2 + i , 0) * (i + 1) * A;
		}
		ans += (long long)N * (L + 1);
	}
	string str; while(str.empty() || ans){str.push_back(ans % 10 + '0'); ans /= 10;}
	reverse(str.begin() , str.end()); cout << str;
	return 0;
}