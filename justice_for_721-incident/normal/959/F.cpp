#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n,q;
int a[100001];
ll p2[100001];
vector<pair<int,int> >qr[100001];
ll ans[100001];
ll boss[20];
int cnt=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	p2[0]=1;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		p2[i]=p2[i-1]*2%mod;
	}
	for(int i=1; i<=q ;i++){
		int u,v;
		cin >> u >> v;
		qr[u].push_back(make_pair(v,i));
	}
	for(int i=1; i<=n ;i++){
		int cur=a[i];
		for(int j=19; j>=0 ;j--){
			if(a[i]&(1<<j)){
				if(boss[j]==0){
					boss[j]=a[i];
					break;
				}
				else a[i]^=boss[j];
			}
		}
		if(a[i]==0) cnt++;
		for(int j=0; j<qr[i].size() ;j++){
			bool hv=true;
			for(int k=19; k>=0 ;k--){
				if(qr[i][j].first&(1<<k)){
					if(boss[k]==0){
						hv=false;
						break;
					}
					qr[i][j].first^=boss[k];
				}
			}
			if(hv) ans[qr[i][j].second]=p2[cnt];
		}
	}
	for(int i=1; i<=q ;i++) cout << ans[i] << '\n';
}