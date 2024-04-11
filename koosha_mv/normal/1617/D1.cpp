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

const int N=1e6+99;

int n,s,t,T,resk,d[2],a[N];
vector<int> ans,v0,v1;

int ask(int a,int b,int c){
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	cin>>resk;
	if(resk==-1) exit(0);
	return resk^1;
}
void Main(){
	s=t=d[0]=d[1]=0;
	v0.clear();
	v1.clear();
	ans.clear();
	
	cin>>n;
	for(int i=1;i<n;i+=3){
		d[ask(i,i+1,i+2)]=i;
	}
	f(i,0,3) v0.pb(d[0]+i);
	f(i,0,3) v1.pb(d[1]+i);
	if(ask(v0[0],v0[1],v1[0])==1){
		t=v1[0];
	}
	else{
		if(ask(v0[0],v0[1],v1[1])==1){
			t=v1[1];
		}
		else{
			s=v0[0];
		}
	}
	//cout<<s<<" : "<<t<<endl;
	if(s>0){
		f(i,0,3){
			f(j,i+1,3){
				if(ask(s,v1[i],v1[j])==1){
					t=v1[i];
				}
			}
		}
	}
	else{
		f(i,0,3){
			f(j,i+1,3){
				if(ask(v0[i],v0[j],t)==0){
					s=v0[i];
				}
			}
		}
	}
	//cout<<s<<" : "<<t<<endl;
	//eror(n);
	ans.pb(t);
	f(i,1,n+1){
		if(i!=s && i!=t && ask(s,t,i)){
			ans.pb(i);
		}
	}
	cout<<"! "<<ans.size()<<" ";
	f(i,0,ans.size()) cout<<ans[i]<<" ";
	cout<<endl;
//	exit(0);
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>T;
	while(T--){
		Main();
	}
}