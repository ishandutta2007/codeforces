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

const int N=1e6+99;

int n,t,res,a[N],mark[N];

int ask(int i,int j,int k){
	cout<<"? "<<i+1<<" "<<j+1<<" "<<k+1<<endl;
	cin>>res;
	return res;
}
void do_it(vector<int> &v){
	int mx=0;
	f(i,0,4){
		a[i]=ask(v[(i+1)%4],v[(i+2)%4],v[(i+3)%4]);
		maxm(mx,a[i]);
	}	
	f(i,0,4){
		f(j,i+1,4){
			if(a[i]==mx && a[j]==mx){
				v.erase(v.begin()+j);
				v.erase(v.begin()+i);
				return ;
			}
		}
	}
	
}
void Main(){
	cin>>n;	
	vector<int> vec;
	f(i,0,4){
		vec.pb(i);
	}
	do_it(vec);
	for(int i=4;i<n;i+=2){
		vec.pb(i);
		if(i+1<n)
			vec.pb(i+1);
		else{
			for(auto x : vec) mark[x]=1;
			f(i,0,n) if(!mark[i]){
				vec.pb(i);
				break;
			}
		}
		do_it(vec);
	}
	f(i,0,n) mark[i]=0;
	cout<<"! "<<vec[0]+1<<" "<<vec[1]+1<<endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		Main();
	}
}