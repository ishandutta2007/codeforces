#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 2e5+7;
int A[N];
bool calc(int n,int k){
	int l =k,r = k;
	ll health = A[k];
	while(l!=1){
		ll mi = 0,sum = 0,lim = 1;
		for(int i = l-1;i>=1;i-=1){
			sum += A[i];
			mi = min(mi,sum);
			if (sum>0){
				lim = i;
				break;
			}
		}
		ll add = sum;
		sum = 0;
		int rlim = r;
		for(int i = r+1;i<=n;i+=1){
			if (sum+health+mi>=0){
				break;
			}
			if (sum+health<0){
				return 0;
			}
			sum += A[i];
			rlim = i;
		}
		if (sum+health+mi<0){
			return 0;
		}
		r = rlim;
		health += sum;
		health += add;
		l = lim;
	}
	return 1;
}
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
	}
	bool res = calc(n,k);
	reverse(A+1,A+1+n);
	k = n-k+1;
	res = max(res,calc(n,k));
	cout<<(res?"YES\n":"NO\n");
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}