#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,a[1005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			while(!(a[i]&1))a[i]/=2;
		}
		sort(a+1,a+n+1);
		priority_queue<int> q;
		for(i=1;i<=n;i++){
			cin>>k;
			while(!(k&1))k/=2;
			q.push(k);
		}
		while(n){
			k=q.top();q.pop();
			if(k<a[n]){
				cout<<"NO\n";goto aaa;
			}
			if(k==a[n]){
				n--;
			}
			else{
				k/=2;q.push(k);
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}