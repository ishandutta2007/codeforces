#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
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

const int N=1e6+99,Q=1000;

int n,k,l,r,mv,a[N];

int ask(int x){
	cout<<"? "<<x+1<<endl;
	cin>>x;
	return x;
}
int Mid(int l,int r){
	if(l<r) return (l+r)/2;
	return ((l+r+n)/2)%n;
}
void find_lr(){
	//vector<int> v;
	//f(i,0,n) v.pb(i);
	//random_shuffle(v.begin(),v.end());	
	int x=0,sq=sqrt(n)-1,u;
	f(i,0,Q){
		x=(x+sq)%n;
		u=ask(x);
		if(u!=k){
			if(u<k){
				l=x,r=(x+i+1)%n;
			}
			else{
				r=x;
				l=(x-i-1+n)%n;
			}
			mv=i;
			break;
		}
	}
}
void solve(){
	//cout<<l<<" "<<r<<endl;
	while((l+1)%n!=r){
		int mid=Mid(l,r);
		if(ask(mid)<k) l=mid;
		else r=mid;
	}
	cout<<"! "<<r+1<<endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	cin>>n>>k;
	find_lr();
	solve();
	
}