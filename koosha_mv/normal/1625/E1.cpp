#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#pragma GCC optimize("Ofast")

const int N=2e6+99,sq=900;

int n,q,m,L,R,a[N],b[N],l[N],r[N],last[N],mark[N];
ll ans,res[N];
string s;

bool cmp(int i, int j){
	int la = l[i]/sq;
	int lb = l[j]/sq;
	if(la==lb){
		if(la&1){
			return r[i]<r[j];
		}
		return (r[i]>r[j]);
	}
	return (la<lb);
}
void op(int x){
	while(R<r[x]){
		ans+=mark[b[++R]]++;
	}
	while(l[x]<L){
		ans+=mark[b[--L]]++;
	}
	while(r[x]<R){
		ans-=--mark[b[R--]];
	}
	while(L<l[x]){
		ans-=--mark[b[L++]];
	}
	res[x]=ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	cin>>s;
	s=' '+s;
	
	last[n]=++m;
	a[0]=n;
	b[0]=last[n];
	f(i,1,n+1){
		a[i]=a[i-1]+(s[i]=='(')-(s[i]==')');
		if(!last[a[i]]){
			last[a[i]]=++m;
		}
		b[i]=last[a[i]];
		last[a[i]+1]=++m;
	}
	cout<<endl;
	f(i,0,q){
		int T;
		cin>>T>>l[i]>>r[i];
		l[i]--;
	}
	vector<int> v(q);
	iota(all(v),0);
	sort(all(v),cmp);
	mark[b[0]]++;
	f(i,0,v.size()){
		op(v[i]);
	}
	f(i,0,q){
		cout<<res[i]<<" ";
	}
}
/*
9 1
)(()())()
2 3 6
2 2 7
2 8 9
2 2 9
*/