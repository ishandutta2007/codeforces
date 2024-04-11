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
#define int ll

const int N=3e4+99,C=5;
const ll inf=2e18;

int n,q,c,t,a[N];
ll s[N][C][C],sum[N][C],w[N][C];

ll RTY(ll x,ll y){
	ll ans=1,res=1;
	if(y==0) return 1;
	y--;
	f(i,1,x+1){
		res=res*(y-i+1)/i;
		ans+=res;
	}
	return ans;
}
void build(){
	f(i,1,n+1){
		f(j,0,c+1){
			int mx=c-j;
			f(k,0,mx+1){
				f(l,0,mx+1){
					if(i+k<=n && i+l<=n && a[i+k]>a[i+l]){
						s[i][j][k]+=RTY(c-j-l,n-i-l);
					}
				}
			}
			sum[i][j]=sum[i-1][j]+s[i][j][0];
		}
	}
	f(i,0,c+1){
		w[n+1][i]=0;
	}
	f_(i,n,1){
		f(j,0,c+1){
			w[i][j]=0;
			f(k,0,c-j+1){
				if(k+i<=n){
					maxm(w[i][j],s[i][j][k]+w[i+k+1][j+k]);
				}
			}
		}
	}
}
void solve(int x,ll res){
	if(res>=RTY(c,n)){
		cout<<-1<<endl;
		return ;
	}
	vector<pair<int,int> > v;
	int now=1,cnt=0;
	while(now<n+1){
		int l=now,r=n+2;
		while(l+1<r){
			int mid=(l+r)/2;
			ll mv=sum[mid-1][cnt]-sum[now-1][cnt];
			if(mv<=res && mv+w[mid][cnt]>=res){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		res-=sum[l-1][cnt]-sum[now-1][cnt];
		now=l;
		if(now==n+1){
			break;
		}
		pair<ll,ll> mx=mp(-1,-1);
		f(i,0,c-cnt+1){
			if(now+i<=n && s[now][cnt][i]<=res){
				maxm(mx,mp(s[now][cnt][i],i));
			}
		}
		v.pb(mp(now,now+mx.S));
		res-=mx.F;
		now+=mx.S+1;
		cnt+=mx.S;
	}
	int ans=x;
	f(i,0,v.size()){
		if(v[i].F<=x && x<=v[i].S){
			ans=v[i].S-(x-v[i].F);
		}
	}
	cout<<a[ans]<<endl;
	
}
void Main(){
	cin>>n>>c>>q;
	f(i,0,n+9){
		f(j,0,C){
			w[i][j]=0;
			sum[i][j]=0;
			f(k,0,C){
				s[i][j][k]=0;
			}
		}
	}
	f(i,1,n+1){
		cin>>a[i];
	}
	build();
	ll o=RTY(c,n);
	f(i,0,q){
		int x;
		ll cnt;
		cin>>x>>cnt;
		solve(x,cnt-1);
	}
}

main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
7 4 10
5 4 6 1 3 2 7
1 47

1
10 4 10
2 9 1 8 10 3 6 7 4 5
1 130
*/