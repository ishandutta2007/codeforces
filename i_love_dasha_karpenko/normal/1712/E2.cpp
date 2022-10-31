#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pp;
#define endl '\n';
const int N = 2e5+7;
const int n = 2e5;
vector<pair<int,int> > Q[N];
int cnt[N];
struct tree{
	ll T[N*4];
	void update(int t,int tl,int tr,int pos,ll add){
		if (tl>pos || tr<pos){
			return;
		}
		if (tl==tr){
			T[t] += add;
			return;
		}
		int tm = (tl+tr)/2;
		update(t+1,tl,tm,pos,add);
		update(t+(tm-tl+1)*2,tm+1,tr,pos,add);
		T[t] = T[t+1] + T[t+(tm-tl+1)*2];
	}
	ll get(int t,int tl,int tr,int l,int r){
		if (tl>r || l>tr){
			return 0;
		}
		if (l<=tl && tr<=r){
			return T[t];
		}
		int tm = (tl+tr)/2;
		return get(t+1,tl,tm,l,r)+get(t+(tm-tl+1)*2,tm+1,tr,l,r);
	}
} T,T1;
ll ans[N];
void solve(){
	int q;
	cin>>q;
	for(int i = 1;i<=q;i+=1){
		int l,r;
		cin>>l>>r;
		Q[l].push_back({r,i});
	}
	for(int l = n;l>=1;l-=1){
		for(int j = l*2;j<=n;j+=l){
			ll dif = -ll(cnt[j])*(cnt[j]-1)/2 + ll(cnt[j]+1)*cnt[j]/2;
			cnt[j] += 1;
			T.update(0,1,n,j,dif);
		}
		for(int j = l*2;j<=n*2;j+=l){
			if (j%6==0 && l<j/3 && l+j/3+j/2>j){
				T1.update(0,1,n*2,j,1);
			}
		}
		for(auto [r,pos]:Q[l]){
			ll len = r-l+1;
			ans[pos] = len*(len-1)*(len-2)/6 - T.get(0,1,n,l,r) - T1.get(0,1,n*2,l,r*2);
//			cout<<"GDB "<<T.get(0,1,n,l,r) <<' '<< T1.get(0,1,n*2,l,r*2)<<endl;
		}
	}
	for(int i = 1;i<=q;i+=1){
		cout<<ans[i]<<endl;
	}
}
signed main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}