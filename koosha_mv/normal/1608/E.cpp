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
#define all(x) x.begin(),x.end()
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+99,S=3;
 
int n,t,ans,a[N],b[N],mcol[N],col[N],X[N],Y[N];
vector<int> p,vec1,vec2,v[N];

void Apply(){
	f(i,0,n){
		col[i]=p[mcol[i]];
	}
}
bool check3(int x){
	int cnt=0,now=0;
	f(i,0,n){
		if(now==0){
			cnt+=a[i];
			if(cnt>=x){
				cnt=0;
				now++;
			}
		}
		else{
			cnt+=b[i];
		}
	}
	f(i,0,n) a[i]=b[i]=0;
	return cnt>=x;
}
bool check2(int x){
	int now=0,cnt=0; f(i,0,n) v[i].clear();
	f(i,0,n){
		v[X[i]].pb(i);
	}
	f(i,0,n){
		for(auto u : v[i]){
			if(col[u]==now){
				cnt++;
			}
		}
		if(cnt>=x){
			cnt=0;
			now++;
			if(now==1){
				f(j,i+1,n){
					for(auto u : v[j]){
						if(col[u]==1){
							a[Y[u]]++;
						}
						if(col[u]==2){
							b[Y[u]]++;
						}
					}
				}
				if(check3(x)){
					return 1;
				}
			}
		}
	}
	return (now==3);
}
bool check1(int x){
	p.resize(3);
	iota(all(p),0);
	do{
		Apply();
		if(check2(x)){
			return 1;
		}
	} while(next_permutation(all(p)));
	return 0;
}
int solve(){
	int l=0,r=n/3+1;
	while(l+1<r){
		int mid=(l+r)/2,res=check1(mid);
		if(res) l=mid;
		else r=mid;
	}
	return l;
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		cin>>X[i]>>Y[i]>>mcol[i];
		vec1.pb(X[i]);
		vec2.pb(Y[i]);
		mcol[i]--;
	}	
	sort(all(vec1));
	sort(all(vec2));
	f(i,0,n){
		X[i]=lower_bound(vec1.begin(),vec1.end(),X[i])-vec1.begin();
		Y[i]=lower_bound(vec2.begin(),vec2.end(),Y[i])-vec2.begin();
	}
	f(T,0,4){
		f(i,0,n){
			if(T==2){
				swap(X[i],Y[i]);
			}
			if(T&1){
				X[i]=n-X[i]-1;
			}
		}
		int res=solve();
		maxm(ans,res);	
	}
	cout<<3*ans;
}