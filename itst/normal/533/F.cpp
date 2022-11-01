#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();}
	return a;
}

const int _ = (1 << 19) | 1;
char S[_] , T[_]; vector < int > ans;
int num1[_] , num2[_] , fir[26] , LS , LT;

namespace NTT{
	const int MOD = 1004535809 , G = 3 , INV = 334845270;
	int dir[_] , need , invnd;

	int poww(long long a , int b){
		int times = 1;
		while(b){
			if(b & 1) times = times * a % MOD;
			a = a * a % MOD; b >>= 1;
		}
		return times;
	}
	
	void init(int len){
		need = 1; while(need < len) need <<= 1;
		invnd = poww(need , MOD - 2);
		for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	}

	void NTT(int *arr , int tp){
		for(int i = 1 ; i < need ; ++i)
			if(i < dir[i]) arr[i] ^= arr[dir[i]] ^= arr[i] ^= arr[dir[i]];
		for(int i = 1 ; i < need ; i <<= 1){
			int wn = poww(tp == 1 ? G : INV , MOD / i / 2);
			for(int j = 0 ; j < need ; j += i << 1){
				long long w = 1;
				for(int k = 0 ; k < i ; ++k , w = w * wn % MOD){
					int x = arr[j + k] , y = arr[i + j + k] * w % MOD;
					arr[j + k] = x + y >= MOD ? x + y - MOD : x + y;
					arr[i + j + k] = x < y ? x + MOD - y : x - y;
				}
			}
		}
		if(tp == -1) for(int i = 0 ; i < need ; ++i) arr[i] = 1ll * arr[i] * invnd % MOD;
	}

	int A[_] , B[_] , C[_] , D[_];
	void calc(){
		reverse(num2 + 1 , num2 + LT + 1); int sum = 0;
		for(int i = 1 ; i <= LT ; ++i){B[i] = num2[i]; D[i] = 1ll * num2[i] * num2[i] % MOD;}
		for(int i = 1 ; i <= LS ; ++i){A[i] = 1ll * num1[i] * num1[i] % MOD; C[i] = num1[i];}
		init(LS + LT + 1); NTT(A , 1); NTT(B , 1); NTT(C , 1); NTT(D , 1);
		for(int i = 0 ; i < need ; ++i){
			A[i] = 1ll * A[i] * B[i] % MOD;
			C[i] = 1ll * C[i] * D[i] % MOD;
		}
		NTT(A , -1); NTT(C , -1); for(int i = 1 ; i <= LT ; ++i) sum = (sum + 1ll * num2[i] * num2[i] * num2[i]) % MOD;

		vector < int > tmp;
		for(int i = LT + 1 ; i <= LS + 1 ; ++i)
			if((A[i] - 2 * C[i] + sum + 2ll * MOD) % MOD == 0) tmp.push_back(i - LT);
		reverse(num2 + 1 , num2 + LT + 1); vector < int > outpos;

		for(int i = 1 ; i <= LT ; ++i) if(!num2[i]) outpos.push_back(i - 1);
		for(auto t : tmp){
			bool flg = 1;
			for(auto p : outpos) if(num1[p + t] && p + t + num1[p + t] < t + LT){flg = 0; break;}
			static int to[26]; memset(to , -1 , sizeof(to));
			for(auto p : outpos){
				int cS = S[p + t] - 'a' , cT = T[p + 1] - 'a';
				if(to[cS] >= 0 && to[cS] != cT || to[cT] >= 0 && to[cT] != cS){flg = 0; break;}
				to[cS] = cT; to[cT] = cS;
			}
			if(flg) ans.push_back(t);
		}
		
	}
}

int main(){
	scanf("%d %d %s %s" , &LS , &LT , S + 1 , T + 1);
	for(int i = LS ; i ; --i){
		num1[i] = fir[S[i] - 'a']; fir[S[i] - 'a'] = i;
		if(num1[i]) num1[i] -= i;
	}
	memset(fir , 0 , sizeof(fir));
	for(int i = LT ; i ; --i){
		num2[i] = fir[T[i] - 'a']; fir[T[i] - 'a'] = i;
		if(num2[i]) num2[i] -= i;
	}
	NTT::calc(); cout << ans.size() << endl;
	for(int i = 0 ; i < ans.size() ; ++i) cout << ans[i] << ' ';
	return 0;
}