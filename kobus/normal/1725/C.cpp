#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define INF INT_MAX
#define pii pair<long long,long long> 
#define f first
#define s second
#define mp make_pair
#define double long double

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)(s.size())
#define int long long
typedef long long ll;
typedef pair<long long,long long> ii;

#define eps 1e-6
#define MOD 998244353
#define MAXN 512345

int tothe(int a,int b){
	if(b==0)return 1;
	if(b==1)return a%MOD;
	if(b%2==0)return tothe((a*a)%MOD,b/2);
	return (a*tothe((a*a)%MOD,b/2))%MOD;
}

int inv(int a){
	return tothe(a,MOD-2);
}

int fat[512345];

int choose(int a,int b){
	return (((fat[a]*inv(fat[b]))%MOD)*inv(fat[a-b]))%MOD;
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(2);

	int n,m;
	cin>>n>>m;
	fat[0]=fat[1]=1;
	for(int i=2;i<=max(n,m);i++)fat[i]=(fat[i-1]*i)%MOD;
	vector<int> d(n+1);
	int len=0;
	d[0]=0;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(i!=0)d[i]+=d[i-1];
		len=d[i];
	}
	d.pop_back();
	set<int> pl;
	for(int i=0;i<n;i++){
		pl.insert(d[i]);
	}
	int p=0;
	for(int i=0;i<n;i++){
		if(len%2==0 && pl.find(d[i]+len/2)!=pl.end())p++;
	}
	int resp=0;
	int np=n-2*p;
	//bruto quantos pares vao ter a mesma cor
	for(int k=0;k<=p;k++){

		int nk=p-k;
		int mr=m-k;

		//cout<<p<<" "<<k<<" "<<nk<<" "<<m<<" "<<mr<<" "<<np<<endl;

		if(k>m)continue;
		if(nk<0)continue;
		if(mr<0)continue;

		//cout<<choose(p,k)<<endl;
		//cout<<choose(m,k)<<endl;
		//cout<<fat[k]<<endl;

		//cout<<fat[2]<<" "<<inv(fat[2])<<endl;

		//jeitos de colorir os pares iguais
		int val=(choose(p,k)*choose(m,k))%MOD;
		val*=fat[k];
		val%=MOD;

		//cout<<val<<endl;

		if(nk>0 && mr<2)continue;

		//jeitos de colorir os pares diferentes
		val*=tothe((mr*(mr-1))%MOD,nk);
		val%=MOD;

		//cout<<val<<endl;
		//cout<<np<<" "<<mr<<endl;

		if(np>0 && mr<1)continue;
		val*=tothe(mr,np);
		val%=MOD;

		//cout<<val<<endl;

		resp+=val;
		resp%=MOD;
	}

	cout<<resp<<endl;
	
}