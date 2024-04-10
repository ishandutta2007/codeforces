#include<bits/stdc++.h>
using namespace std;
const int N=1<<20;
int n,k;
int t[N],b[N];
int id[N];
typedef long long ll;
ll sumk;
multiset<int>st;
int main(){
	scanf("%d%d",&n,&k);
//	n=3e5;k=1;
	for(int i=0;i<n;++i){
		scanf("%d%d",t+i,b+i);
//		t[i]=rand();b[i]=rand();
		id[i]=i;
	}
	sort(id,id+n,[&](int x,int y){
		return b[x]>b[y];
	});
	ll ans=0;
	for(int ii=0;ii<n;++ii){
		int i=id[ii];
		sumk+=t[i];
		st.insert(t[i]);
		if(st.size()>k){
			auto it=st.begin();
			sumk-=*it;
			st.erase(it);
		}
		ans=max(ans,sumk*b[i]);
	}
	printf("%lld\n",ans);
	return 0;
}