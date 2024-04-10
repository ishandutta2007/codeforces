#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e7 + 10;
int spf[N];
long long cntspf[N];
int phi[N];
bool invalid[N];
void pre(){
	for(int i = 2; i * i < N; i++){
		if(!spf[i]){
			for(int j = i * i; j < N; j += i)
				if(!spf[j])
					spf[j] = i;
		}
	}
	for(int i = 2; i < N; i++) if(!spf[i])
		spf[i] = i;
	phi[1] = 1;
	for(int i = 2; i < N; i++){
		int p = spf[i];
		if(p == i){
			phi[i] = i - 1;
			continue;
		}
		int x = i / p;
		if(x % p == 0) phi[i] = phi[x] * p;
		else phi[i] = phi[x] * (p - 1);
	}
}

int main(){
	pre();
	int n;
	cin >> n;
	long long x = 0;
	long long disconnected = 1;
	invalid[1] = 1;
	for(int i = 1; i <= n; i++){
		if(2 * spf[i] > n && spf[i] == i){
			disconnected++;
			invalid[i] = 1;
		}
	}
	long long valid = n - disconnected;
	long long paths = (n * 1ll * (n - 1)) / 2;
	long long P= paths;
	long long ans = 0;
	for(int i = 2; i <= n; i++){
		paths -= phi[i];
	}
		
	ans += paths; // dist = 1
	// spf[i] * spf[j] <= n
	for(int i = 2; i <= n; i++){
		cntspf[spf[i]]++;
	}

	for(int i = 2; i <= n; i++)
		cntspf[i] += cntspf[i - 1];
	ll sm = 0;
	for(int i = 2; i <= n; i++){
		sm += cntspf[n / spf[i]];
		sm -= (spf[i] * 1ll * spf[i] <= n);
	}	

	ans += (sm / 2 - paths) * 2;
	ans += ((valid * (valid - 1)) / 2 - sm / 2) * 3;
	cout << ans;
}