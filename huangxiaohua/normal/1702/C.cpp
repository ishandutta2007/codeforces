#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		map<int,int> mn,mx;
		for(i=1;i<=n;i++){
			cin>>k;
			if(mn.count(k)==0)mn[k]=i;
			mx[k]=i;
		}
		while(m--){
			cin>>i>>j;
			if(mn.count(i)==0||mn.count(j)==0){
				cout<<"NO\n";continue;
			}
			if(mn[i]>mx[j])cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}