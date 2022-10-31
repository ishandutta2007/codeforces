//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
#define hash sadsad
const int N = 1e6+100;
const int MOD = 1e9+123;
const int base = 31;
struct hash{
	ull h1;
	ll h2;
	hash(int num = 0){
		h1 = h2 = num;
	}
} H[N],pr[N];
const hash operator + (hash a,hash b){
	a.h1 += b.h1;
	a.h2 += b.h2;
	if (a.h2>=MOD){
		a.h2 -= MOD;
	}
	return a;
}
const hash operator * (hash a,ll mult){
	a.h1 *= mult;
	a.h2 = (a.h2*mult)%MOD;
	return a;
}
const hash operator * (hash a,hash b){
	a.h1 *= b.h1;
	a.h2 *= b.h2;
	a.h2 %= MOD;
	return a;
}
const hash operator - (hash a,hash b){
	a.h1 -= b.h1;
	a.h2 += MOD-b.h2;
	while(a.h2>=MOD){
		a.h2-=MOD;
	}
	return a;
}
const bool operator == (hash a,hash b){
	return a.h1==b.h1 && a.h2==b.h2;
}
const bool operator < (const hash &a,const hash &b){
	if (a.h1==b.h1){
		return a.h2<b.h2;
	}
	return a.h1<b.h1;
}
int gi(char ch){
	return ch-'a'+1;
}
hash get(int l,int r){
	return H[r]-(H[l-1]*pr[r-l+1]);
}
const int M = 1e5+7;
string t[M];
vector<int> ans[M];
void solve(){
	string s;
	cin>>s;
	s = '#' + s;
	int n = s.size() - 1;
	for(int i = 1;i<=n;i+=1){
		H[i] = (H[i-1]*base) + hash(gi(s[i]));
	}
	for(int i = n;i>=1;i-=1){
		int len = n-i+1;
	}
	int q;
	cin>>q;
	for(int i = 1;i<=q;i+=1){
		cin>>t[i];
		for(int j = n+1;j<=n+t[i].size();j+=1){
			H[j] = (H[j-1]*base) + hash(gi(t[i][j-n-1]));
			int len = 0;
			for(int k = n+1;k<=j;k+=1){
				if (get(k,j)==get(1,j-k+1)){
					len = j-k+1;
					break;
				}
			}
			for(int delta = 1;delta<=j-n;delta+=1){
				if (get(1,j-delta)==get(delta+1,j)){
					len = max(len,j-delta);
				}
			}
			ans[i].push_back(len);
		}
	}
	for(int add = 1;add<=10;add+=1){
		map<hash,int> M;
		for(int i = 1;i<=n;i+=1){
			if (n-i+1+add>n){
				continue;
			}
			int len = n-i+1;
			if (!(get(1,len)==get(i,n))){
				continue;
			}
			hash h = H[len+add]-(pr[add]*get(i,n));
			int val = M[h];
			val = max(val,len+add);
			M[h] = val;
		}
		for(int i = 1;i<=q;i+=1){
			if (add>t[i].size()){
				continue;
			}
			for(int j = n+1;j<=n+add;j+=1){
				H[j] = (H[j-1]*base) + hash(gi(t[i][j-n-1]));
			}
			int j = n+add;
			ans[i][j-n-1] = max(ans[i][j-n-1],M[get(n+1,j)]);		
		}
	}
	for(int i = 1;i<=q;i+=1){
		for(int j = 0;j<t[i].size();j+=1){
			cout<<ans[i][j]<<' ';
		}
		cout<<endl;
	}

}
signed main(){
	pr[0] = hash(1);
	for(int i = 1;i<N;i+=1){
		pr[i] = pr[i-1]*base;
	}
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}