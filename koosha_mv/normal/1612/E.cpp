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
#define int ll

const int N=2e5+99,mod=1e9+7,K=22;

int n,t,m[N],k[N],pum[N],sum[N];
pair<int,int> ans;
vector<int> Ans,v[N];

bool cmp(int i,int j){
	return sum[i]>sum[j];
}
int G(pair<int,int> u,pair<int,int> v){
	return u.F*v.S>v.F*u.S;
}
void case1(){
	f(i,1,K){
		f(j,0,N){
			sum[j]=0;
			f(p,0,v[j].size()){
				sum[j]+=min(i,v[j][p]);
			}
		}
		vector<int> v;
		f(j,0,N){
			v.pb(j);
		}
		sort(v.begin(),v.end(),cmp);
		int res=0;
		f(j,0,i){
			res+=sum[v[j]];
		}
		if(G(mp(res,i),ans)){
			Ans.clear();
			ans=mp(res,i);
			f(j,0,i){
				Ans.pb(v[j]);
			}
		}
	}
//	cout<<ans.F<<" "<<ans.S<<endl;
//	cout<<Ans.size()<<endl;
//	f(i,0,Ans.size()){
///		cout<<Ans[i]<<" ";
	//}
	//cout<<endl;
}
void case2(){
	f(j,0,N){
		sum[j]=0;
		f(p,0,v[j].size()){
			sum[j]+=v[j][p];
		}
	}
		
	vector<int> v;
	f(i,0,N) v.pb(i);
	sort(v.begin(),v.end(),cmp);
	int res=0,mv=-1;
	f(i,0,N){
		res+=sum[v[i]];
		if(i>=K-2 && G(mp(res,i+1),ans)){
			mv=i;
			ans=mp(res,i+1);
		}
	}
	if(mv!=-1){
		Ans.clear();
		f(i,0,mv+1){
			Ans.pb(v[i]);
		}
	}
	//cout<<ans.F<<" "<<ans.S<<endl;
}

main(){
	ans=mp(0,1);
	
	cin>>n;
	f(i,0,n){
		cin>>m[i]>>k[i];
		m[i]--;
		v[m[i]].pb(k[i]);
	}	
	case1();
	case2();
	cout<<Ans.size()<<endl;
	f(i,0,Ans.size()){
		cout<<Ans[i]+1<<" ";
	}
}