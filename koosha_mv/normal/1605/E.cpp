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

const int N=2e6+99,Max=1e6+9;

int n,t,q,tr,ca1,res,a[N],b[N],c[N],fa[N],fb[N],sa[N],sb[N],ans[N*2];
vector<int> v[N];

void solvea(){
	f(i,1,n+1){
		for(int j=i*2;j<=n;j+=i){
			a[j]-=a[i];
		}
		res+=abs(a[i]);
		//cout<<a[i]<<" ";
	}
	//cout<<endl;
	c[1]=1;
	f(i,1,n+1){
		for(int j=i*2;j<=n;j+=i){
			c[j]-=c[i];
		}
		//cout<<c[i]<<" ";
	}
//	cout<<endl;
	f(i,1,n+1){
		if(a[i]<0){
			a[i]=-a[i];
			c[i]=-c[i];
		}
		tr+=c[i];
		if(c[i]<0){
			int x=abs(c[i]);
			v[min((a[i]+x-1)/x,N-1)].pb(i);
			//eror((a[i]+x-1)/x);
			a[i]=a[i]%x;
			if(a[i]==0) a[i]=x;
		}
	}
}
void PRT(){
	f(i,0,N){
		ans[i]=res;
		//cout<<i<<" res "<<res<<endl;
		res+=tr;
		f(j,0,v[i+1].size()){
			int x=v[i+1][j];
			//eror(i);
			//cout<<x<<" : "<<2*(a[x]+c[x])-c[x]<<endl;
			res+=-2*(a[x]+c[x]);
			tr+=-2*c[x];
			//eror(tr);
		}
	}
}

main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	ca1=a[1];
	f(i,1,n+1){
		cin>>b[i];
	}
	a[1]=-Max;
	f(i,2,n+1){
		a[i]=b[i]-a[i];
	}
	solvea();
	PRT();
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		x=x-ca1;
		x=Max+x;
		cout<<ans[x]<<endl;
	}
}
/*
2
3 7
-1 5
1
4
*/