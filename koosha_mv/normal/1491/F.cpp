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

int n,t,a[N];
vector<int> v,ans;

void del(int x){
	f(i,0,v.size()){
		if(v[i]==x){
			v.erase(v.begin()+i);
			return ;
		}
	}
}
int calc(int x){
	int res;
	cout<<"? 1 "<<v.size()-1<<endl;
	cout<<x<<endl;
	f(i,0,v.size()) if(x!=v[i])cout<<v[i]<<" ";
	cout<<endl;
	cin>>res;
	return res;
}
int ask(int x,int u){
	int res;
	cout<<"? "<<1<<" "<<x+1<<endl;
	cout<<u<<endl;
	f(i,0,x+1) cout<<ans[i]<<" ";
	cout<<endl;
	cin>>res;
	return res;
}
void Main(){	
	int u=-1;
	cin>>n;
	f(i,1,n+1){
		v.pb(i);
	}
	f(i,1,n){
		int x=calc(i);
		if(x==0){
			ans.pb(i);
			del(i);
		}
		else{
			u=x;
		}
	}
	int l=-1,r=ans.size();
	while(l+1<r){
		int mid=(l+r)/2;
		if(ask(mid,v[0])!=0) r=mid;
		else l=mid;
	}
	if(r!=ans.size()){
		ans.erase(ans.begin()+r);
		if(v.size()%2==1){
			ans.pb(n);
		}
	}
	else{
		if(v.size()%2==abs(u)%2){
			ans.pb(n);
		}
	}
	
	cout<<"! "<<ans.size()<<" ";
	f(i,0,ans.size()) cout<<ans[i]<<" ";
	cout<<endl;
	
	v.clear();
	ans.clear();
	return ;
}

int main(){
	cin>>t;
	f(T,0,t){
		Main();
	}
}