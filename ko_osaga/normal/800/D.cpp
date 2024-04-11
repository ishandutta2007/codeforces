#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;
const lint mod = 1e9 + 7;

int n, a[1000005];
lint p2[1000005];
lint ans[1000005];
lint cnt[1000005], sum[1000005], sqs[1000005];

lint b[64], pcnt[64];

lint solve(int i){
	lint sum2 = sum[i], sqsum = sqs[i], cnt2 = cnt[i];
	if(cnt2 == 0) return 0;
	if(cnt2 == 1) return sqsum;
	return (p2[cnt2 - 1] * sqsum + ((sum2 * sum2 - sqsum + mod) % mod) * p2[cnt2 - 2]) % mod;
}

void precalc(){
	for(int i=0; i<64; i++){
		int cur = 1;
		for(int j=0; j<6; j++){
			if((i >> j) & 1){
				b[i] += cur;
				pcnt[i]++;
			}
			cur *= 10;
		}
	}
	for(int i=999999; i>=0; i--){
		int msk = 0, cur = i;
		for(int j=0; j<6; j++){
			if(cur % 10 == 9) msk |= (1<<j);
			cur /= 10;
		}
		lint t1 = sum[i];
		lint t2 = cnt[i];
		lint t3 = sqs[i];
		for(int j=1; j<64; j++){
			if(msk & j) continue;
			if(pcnt[j] % 2 == 0){
				t1 += mod - sum[i + b[j]];
				t2 += mod - cnt[i + b[j]];
				t3 += mod - sqs[i + b[j]];
			}
			else{
				t1 += sum[i + b[j]];
				t2 += cnt[i + b[j]];
				t3 += sqs[i + b[j]];
			}
		}
		sum[i] = t1 % mod;
		cnt[i] = t2 % mod;
		sqs[i] = t3 % mod;
	}
}

int main(){
	scanf("%d",&n);
	p2[0] = 1;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		sum[a[i]] += a[i];
		sqs[a[i]] += 1ll * a[i] * a[i] % mod;
		cnt[a[i]]++;
		sum[a[i]] %= mod;
		sqs[a[i]] %= mod;
		p2[i+1] = p2[i] * 2 % mod;
	}
	precalc();
	lint ret = 0;
	for(int i=0; i<1000000; i++){
		ans[i] = solve(i);
	}
	for(int i=0; i<=999999; i++){
		int msk = 0, cur = i;
		for(int j=0; j<6; j++){
			if(cur % 10 == 9) msk |= (1<<j);
			cur /= 10;
		}
		for(int j=1; j<64; j++){
			if(msk & j) continue;
			if(pcnt[j] % 2 == 1){
				ans[i] += mod - ans[i + b[j]];
			}
			else{
				ans[i] += ans[i + b[j]];
			}
			ans[i] %= mod;
		}
	}
	for(int i=0; i<1000000; i++){
		ret ^= i * ans[i];
	}
	cout << ret;
}