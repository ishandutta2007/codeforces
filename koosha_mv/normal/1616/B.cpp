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
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,t,a[N];

void Main(){
	string s,res1,res2;
	cin>>n>>s;
	if(n==1){
		cout<<s<<s<<endl;
		return ;
	}
	if(s[0]==s[1]){
		cout<<s[0]<<s[0]<<endl;
		return ;
	}
	f(i,0,n){
		res1+=s[i];
		if(i==n-1 || s[i]<s[i+1]){
			break;
		}
	}
	res2=res1;
	while(res2.size()>1 && res2[res2.size()-1]==res2[res2.size()-2]){
		res2.pop_back();
	}
	int sz=res1.size()-1;
	f_(i,sz,0){
		res1+=res1[i];
	}
	sz=res2.size()-1;
	f_(i,sz,0){
		res2+=res1[i];
	}

	if(res1<res2) cout<<res1<<endl; 
	else cout<<res2<<endl;
}

main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//t=1;
	cin>>t;
	while(t--){
		Main();
	}	
}