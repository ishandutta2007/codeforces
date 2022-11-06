#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505;
ll n,d[N][N],x[N],a[N],dist[N][N];
void upd(ll &a,ll b){
	if(b<a)a=b;
}
int main(){
	//freopen("input.txt","r",stdin); 
	cin>>n;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)cin>>d[i][j],dist[i][j]=1ll<<60;
	for(ll i=1;i<=n;i++)cin>>x[i],dist[i][i]=0;
	for(ll i=n;i;i--){
		for(ll j=i+1;j<=n;j++){
			for(ll k=i+1;k<=n;k++){
				upd(dist[x[i]][x[k]],d[x[i]][x[j]]+dist[x[j]][x[k]]);
				upd(dist[x[k]][x[i]],dist[x[k]][x[j]]+d[x[j]][x[i]]);
			}
		}
		for(ll j=i+1;j<=n;j++){
			for(ll k=i+1;k<=n;k++){
				upd(dist[x[j]][x[k]],dist[x[j]][x[i]]+dist[x[i]][x[k]]);
			}
		}
		for(ll j=i;j<=n;j++){
			for(ll k=i;k<=n;k++){
				a[i]+=dist[x[j]][x[k]];
			}
		}
		/*for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				if(dist[j][k]==1ll<<60)cout<<"inf ";
				else cout<<dist[j][k]<<' ';
			}
			cout<<endl;
		}*/
	}
	for(ll i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}