#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200100,mod=998244353;
int a[N],ia[N],b[N],t[N];
int n,k;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n>>k;
		for(int i=0;i<=n;++i)a[i]=ia[i]=b[i]=t[i]=0;
		for(int i=0;i<n;++i){cin>>a[i];ia[a[i]]=i;}
		for(int i=0;i<k;++i){cin>>b[i];t[b[i]]=i+1;}
		set<int>ar;
		for(int i=0;i<n;++i)ar.insert(i);
		ll res=1;
		for(int i=0;i<k;++i){
			auto it=ar.find(ia[b[i]]);
			if((it==ar.begin()||t[a[*prev(it)]]>t[b[i]])&&(next(it)==ar.end()||t[a[*next(it)]]>t[b[i]]))res*=0;
			if((it!=ar.begin()&&t[a[*prev(it)]]<t[b[i]])&&(next(it)!=ar.end()&&t[a[*next(it)]]<t[b[i]]))res=(res*2)%mod;
			ar.erase(it);
		}
		cout<<res<<endl;
	}
}