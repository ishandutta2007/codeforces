#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
#define M 1000000007

int i,j,k,n,t,m,sb[200500],k2;
set<pair<int,int> >s;
ll res;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		s.clear();
		for(i=1;i<=n;i++){
			cin>>k;
			s.insert({-k,i});
		}
		k=0;k2=0;m=0;
		res=0;
		for(auto [i,j]:s){
			if(!m){
				sb[j]=++k;
				res-=1ll*i*k;
			}
			else{
				sb[j]=--k2;
				res+=1ll*i*k2;
			}
			m^=1;
		}
		cout<<res*2<<'\n';
		for(i=0;i<=n;i++){
			cout<<sb[i]<<' ';
		}
		cout<<'\n';
	}
}