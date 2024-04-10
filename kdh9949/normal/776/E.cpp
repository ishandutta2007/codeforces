#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
const int b = 1000001;
int ip[1000010];
vector<int> p;

int main(){
	for(int i = 2; i <= b; i++){
		if(ip[i]) continue;
		if(i * i > b) break;
		for(int j = i * i; j <= b; j += i) ip[j] = 1;
	}
	for(int i = 2; i <= b; i++) if(!ip[i]) p.push_back(i);
	scanf("%lld%lld", &n, &k);
	k = (k + 1) / 2;
    while(k-- && n > 1){
		ll nn = n;
		for(auto &i : p){
			if(n % i == 0){
				nn /= i;
				nn *= (i - 1);
				while(n % i == 0) n /= i;
			}
		}
		if(n != 1){ nn /= n; nn *= (n - 1); }
		n = nn;
    }
    printf("%lld", n % 1000000007);
	return 0;
}