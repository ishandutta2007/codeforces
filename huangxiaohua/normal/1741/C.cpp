#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,res,a[10050],lst,t1;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		map<ll,ll> mp;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			a[i]+=a[i-1];
			mp[a[i]]=i;
		}
		res=n;
		for(i=1;i<n;i++){
			if(a[n]%a[i])continue;
			t1=i;
			lst=i;
			for(j=2;;j++){
				if(!mp[j*a[i]])goto aaa;
				t1=max(t1,mp[j*a[i]]-lst);
				lst=mp[j*a[i]];
				if((j*a[i])==a[n])break;
			}
			res=min(res,t1);
			aaa:;
		}
		cout<<res<<'\n';
	}
}