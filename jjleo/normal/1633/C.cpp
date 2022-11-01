#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll hc, dc, hm, dm, k, w, a;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld%lld%lld%lld%lld%lld", &hc, &dc, &hm, &dm, &k, &w, &a);
		bool tag = false;
		for(int i = 0;i <= k;i++){
			ll cnt = (hc + a * i + dm - 1) / dm;
			if((__int128)cnt * (dc + w * (k - i)) >= hm){
				tag = true;
				break;
			}
		}
		puts(tag ? "YES" : "NO");
	}
}