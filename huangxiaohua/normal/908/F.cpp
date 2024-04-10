#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v,v1[300500],v2[300500];
string s;
int i,j,k,n,m,a[300500],ty[300500],it;
ll res,mx1,mx2;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	v.push_back(-1);
	for(i=1;i<=n;i++){
		cin>>k>>s;
		a[i]=k;
		if(s[0]=='R'){ty[i]=1;v1[it].push_back(k);}
		if(s[0]=='G'){ty[i]=2;v.push_back(k);it++;}
		if(s[0]=='B'){ty[i]=3;v2[it].push_back(k);}
	}
	if(it&&v1[0].size()){res+=v[1]-v1[0][0];}
	if(it&&v2[0].size()){res+=v[1]-v2[0][0];}
	k=v1[it].size();
	if(it&&k){res+=v1[it][k-1]-v[it];}
	k=v2[it].size();
	if(it&&k){res+=v2[it][k-1]-v[it];}
	for(i=1;i<it;i++){
		mx1=mx2=0;
		k=v1[i].size();
		if(!k){mx1=v[i+1]-v[i];goto aaa;}
		for(j=1;j<k;j++){
			mx1=max(mx1,v1[i][j]-v1[i][j-1]);
		}
		mx1=max(v1[i][0]-v[i],mx1);
		mx1=max(v[i+1]-v1[i][k-1],mx1);
		aaa:k=v2[i].size();
		if(!k){mx2=v[i+1]-v[i];goto bbb;}
		for(j=1;j<k;j++){
			mx2=max(mx2,v2[i][j]-v2[i][j-1]);
		}
		mx2=max(v2[i][0]-v[i],mx2);
		mx2=max(v[i+1]-v2[i][k-1],mx2);
		bbb:res+=min((v[i+1]-v[i])*2,(v[i+1]-v[i])*3-mx1-mx2);
	}
	if(!it){
		k=v1[0].size();
		if(k){res+=v1[0][k-1]-v1[0][0];}
		k=v2[0].size();
		if(k){res+=v2[0][k-1]-v2[0][0];}
	}
	cout<<res;
}