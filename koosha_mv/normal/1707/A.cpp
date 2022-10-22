#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

int n,q,t;
int a[N],b[N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		string s;
		cin>>n>>q;
		f(i,0,n){
			cin>>a[i];
			s+='0';
		}
		int res=0,sum=0,pos=n;
		b[n-1]=1;
		f_(i,n-2,0){
			b[i]=b[i+1];
			if(b[i]<a[i]){
				b[i]=b[i+1]+1;
			}
		}
		f(i,0,n){
			if(q>=b[i] && n-i+sum>=res){
				res=n-i+sum;
				pos=i;
			}
			if(a[i]<=q){
				sum++;
			}
		}
		f(i,0,pos){
			if(a[i]<=q){
				s[i]='1';
			}
		}
		f(i,pos,n){
			s[i]='1';
		}
		cout<<s<<'\n';
	}
}
/*
5
1 1
1
2 1
1 2
3 1
1 2 1
4 2
1 4 3 1
5 2
5 1 2 4 3
*/