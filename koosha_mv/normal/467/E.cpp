#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N],b[N],cnt[N],last[N];
pair<int,int> seg[N];
vector<int> ans;

void upd(int s,int t,int x){
	s=s-1+n;
	while(s){
		maxm(seg[s],mp(t,x));
		s/=2;
	}
}
pair<int,int> get(int l, int r) {
	pair<int,int> ans=mp(0,0);
	l--,r--;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) maxm(ans,seg[l++]);
		if (r&1) maxm(ans,seg[--r]);
	}
	return ans;
}

int main(){
	int l=0;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	f(i,1,n+1){
		a[i]=lower_bound(b+1,b+1+n,a[i])-b;
		if(last[a[i]] && get(l+1,last[a[i]]).F>last[a[i]]){
			ans.pb(get(l+1,last[a[i]]).S);
			ans.pb(a[i]);
			ans.pb(get(l+1,last[a[i]]).S);
			ans.pb(a[i]);
			
			f(j,l+1,i+1){
				cnt[a[j]]=0;
				last[a[j]]=0;
			}
			l=i;
			continue;
		}
		if(cnt[a[i]]>2){
			ans.pb(a[i]);
			ans.pb(a[i]);
			ans.pb(a[i]);
			ans.pb(a[i]);
			
			f(j,l+1,i+1){
				cnt[a[j]]=0;
				last[a[j]]=0;
			}
			l=i;
			continue;
		}
		if(last[a[i]]){
			upd(last[a[i]],i,a[i]);
		}
		cnt[a[i]]++;
		last[a[i]]=i;
	}
	cout<<ans.size()<<endl;
	f(i,0,ans.size()){
		cout<<b[ans[i]]<<" ";
	}
}