#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define L(x) (2*(x))
#define R(x) (2*(x)+1)

const int N=1<<20;
int teams[N],state[N];
string s;
int k,q,n;

int getval(int i){
	return teams[L(i)]*!!(state[i]&2)+teams[R(i)]*(state[i]&1);
}

void update(int idx,int l,int r,int tl,int tr,int val){
//	cerr<<idx<<" "<<l<<" "<<r<<" "<<tl<<" "<<tr<<endl;
	if(l==tl&&r==tr){
		state[idx]=val;
		teams[idx]=getval(idx);
		return;
	}
	int m=(l+r)/2;
	if(m<=tl)update(R(idx),m,r,tl,tr,val);
	else update(L(idx),l,m,tl,tr,val);
	teams[idx]=getval(idx);
}

void ProGamerMove(){
	cin>>k>>s>>q;
	n=1<<k;
	reverse(s.begin(),s.end());
	for(int i=n;i<2*n;++i)teams[i]=1;
//	cerr<<s<<endl;
	for(int i=n-1;i>=1;--i){ // 2 == rght
		state[i]=s[i-1]=='?'?3:s[i-1]-'0'+1;
		teams[i]=getval(i);
//		cerr<<i<<" "<<teams[i]<<endl;
	}
	while(q--){
		int p,ns;
		char c;cin>>p>>c;p=n-p;
		ns=c=='?'?3:c-'0'+1;
		int l=p,r=p;
		while(l<n)l<<=1;
		while(r<n)r=2*r+1;
//		cerr<<l<<" "<<r<<endl;
		update(1,n,2*n,l,r+1,ns);
		cout<<teams[1]<<"\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}