#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll n,t,ans[N],p=0,b,k,an,l,r,mid,cnt=1;
string s;
vector<int> v[32];
ll binary_search(ll x,ll y){
	if(v[y].size()==0) return -1;
	l=-1,r=v[y].size(),mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(v[y][mid]<=x)
			l=mid;
		else
			r=mid;
	}
	if(r==v[y].size()) return -1;
	return r;
}
int main(){
	cin>>n>>s;
	s='a'+s;
	f(i,1,n+1)
		v[s[i]-'a'].pb(i);

	while(t<n){
		//cout<<p<<" "<<cnt<<endl;
		ans[p]=cnt;
		b=1e9;
		f(i,s[p]-'a',29){
			k=binary_search(p,i);
			if(k!=-1 && v[i][k]<b){
				b=v[i][k],an=i;
			}
		}
		if(b==1e9)
			p=0,cnt++;
		else{
			t++;
			k=binary_search(p,an);
			//cout<<an<<" ::: "<<k<<endl;
			v[an].erase(v[an].begin()+k);
			p=b;
		}
	}
	ans[p]=cnt;
	cout<<cnt<<endl;
	f(i,1,n+1)
		cout<<ans[i]<<" ";
}