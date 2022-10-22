#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=8e5+9;
int n,q;
map<int,int>mp;
int f[M],a[M],b[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	if(mp.count(y))y=mp[y],f[find(x)]=find(y);
	else mp[y]=find(x),a[find(x)]=y;
}
void cover(int l,int r,int x){
	for(auto it=mp.lower_bound(l);it!=mp.end()&&it->fi<=r;it=mp.erase(it)){
		merge(it->se,x);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		a[i]=x;
		b[i]=f[i]=i;
		merge(i,x);
	}
	cin>>q;
	for(int i=1;i<=q;++i){
		int o,l,r;
		cin>>o;
		if(o==1){
			cin>>l>>r;
			n++;
			b[l]=f[n]=n;
			a[n]=r;
			merge(n,r);
		}
		if(o==2){
			cin>>l;
			cout<<a[find(b[l])]<<"\n";
		}
		if(o==3){
			cin>>l>>r;
			int mid=(l+r)>>1;
			cover(l,mid,l-1);
			cover(mid+1,r,r+1);
		}
	}
	return 0;
}
/*
5
2 6 5 6 2
2
3 3 6
2 3
*/