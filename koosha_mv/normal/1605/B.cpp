#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N];
string s;

void Main(){
	cin>>n>>s;
	int cnt0=0,cnt1=0;
	vector<int> v;
	f(i,0,n){
		if(s[i]=='0') cnt0++;
		else cnt1++;
	}	
	f(i,0,n){
		if(i<cnt0 && s[i]=='1'){
			v.pb(i);
		}
		if(i>=cnt0 && s[i]=='0'){
			v.pb(i);
		}
	}
	if(v.size()==0) cout<<0<<endl;
	else{
		cout<<1<<endl<<v.size()<<" ";
		f(i,0,v.size()) cout<<v[i]+1<<" "; cout<<endl;
	}
}

int main(){
	cin>>t;
	while(t--){
		Main();
	}
}