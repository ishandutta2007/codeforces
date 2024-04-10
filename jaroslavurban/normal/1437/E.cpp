#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500100,inf=1e9;
ll a[N],b[N];
int n,k;
ll res;

// returns indexes of longest strictly increasing subsequence
template<class T>
vector<T>lis(vector<T>a){
	int n=a.size(),len=0;
	vector<T>bst(n),p(n,-1),res; // index of lowest value for given length, index of previous value, resuling vector
	for(int i=0;i<n;++i){
		auto it=lower_bound(bst.begin(),bst.begin()+len,i,[&](T u,T v){
			return a[u]<=a[v]; // STRICTLY INCREASING BY DEFAULT
		}); 
		*it=i;
		if(it==bst.begin()+len)++len;
		if(it!=bst.begin())p[i]=*prev(it);
	}
	assert(n);
	for(int idx=bst[len-1];~idx;idx=p[idx])res.push_back(idx);
	reverse(res.begin(),res.end());
	return res;
}

bool solve(vector<ll>seg,ll l,ll r){
	if(l+(int)seg.size()>=r)return false;
	if(seg.empty())return true;
	vector<ll>modseg;
	for(int i=0;i<seg.size();++i)if(seg[i]>r-(int)seg.size()+i||seg[i]-i<=l)++res;
	else modseg.push_back(seg[i]-i-1);
	if(modseg.empty()){
		res+=(int)modseg.size();
		return true;
	}
	auto rr=lis(modseg);
	res+=(int)modseg.size()-(int)rr.size();
	return true;
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=k;++i)cin>>b[i];
	a[n+1]=1e10;
	a[0]=-1e10;
	b[k+1]=n+1;
	int cur=0;
	bool pos=true;
	vector<ll>seg;
	for(int i=0;i<=k;++i){
		seg.clear();
		for(int j=b[i]+1;j<b[i+1];++j)seg.push_back(a[j]);
		if(!solve(seg,a[b[i]],a[b[i+1]])){pos=false;break;}
	}
	if(pos)cout<<res<<endl;
	else cout<<-1<<endl;
}