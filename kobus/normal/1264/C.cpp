#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123
#define INF LLONG_MAX
#define MOD 998244353 
#define pii pair<int,int> 
#define int long long
 
int tothe(int a,int b){
	if(b==0)return 1;
	if(b%2)return (a*tothe((a*a)%MOD,b/2))%MOD;
	else return tothe((a*a)%MOD,b/2);
}
 
int inv(int x){
	return tothe(x,MOD-2);
}
 
int prefmul[1123456];
int prefsoma[1123456];
bool check[1123456];
int ans;
 
//inclusivo dos dois lados
void removeIntervalo(int a,int b){
	//cout<<"remove "<<a<<" "<<b<<endl;
	int baixo=prefmul[b];
	if(a!=0)baixo*=inv(prefmul[a-1]);
	baixo%=MOD;
 
	int cima=prefsoma[b-1];
	if(a>1){
		cima-=prefsoma[a-2];
		cima+=MOD;
		cima%=MOD;
	}
	if(a==0)cima++;
	else cima*=inv(prefmul[a-1]);
	cima%=MOD;
 
	int parte=(cima*inv(baixo))%MOD;

	ans-=parte;
	ans+=MOD;
	ans%=MOD;
	//cout<<parte<<" "<<cima<<" "<<baixo<<" "<<ans<<endl;
}
 
//inclusivo dos dois lados
void insereIntervalo(int a,int b){
	//cout<<"insere "<<a<<" "<<b<<endl;
	int baixo=prefmul[b];
	if(a!=0)baixo*=inv(prefmul[a-1]);
	baixo%=MOD;
 
	int cima=prefsoma[b-1];
	if(a>1){
		cima-=prefsoma[a-2];
		cima+=MOD;
		cima%=MOD;
	}
	if(a==0)cima++;
	else cima*=inv(prefmul[a-1]);
	cima%=MOD;
 
	int parte=(cima*inv(baixo))%MOD;

	ans+=parte;
	ans%=MOD;
	//cout<<parte<<" "<<cima<<" "<<baixo<<" "<<ans<<endl;;
}
 
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n;
	cin>>n;
	int q;
	cin>>q;
	int prob=1;
	int cima=0;
	int baixo=1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int inver=(x*inv(100))%MOD;
		cima+=baixo;
		cima%=MOD;
		baixo*=inver;
		baixo%=MOD;
		prefmul[i]=baixo;
		if(i==0)prefsoma[i]=inver;
		else prefsoma[i]=(prefsoma[i-1]+baixo)%MOD;
		//cout<<prefsoma[i]<<" ";
	}
	//cout<<endl;
	check[0]=1;
	ans=(cima*inv(baixo))%MOD;

	//cout<<cima<<" "<<baixo<<" "<<ans<<endl;
 
	set<pii> coisas;
	coisas.insert(mp(0,n-1));
	while(q--){
		int x;
		cin>>x;
		x--;
		check[x]=!check[x];
		//to inserindo o ponto
		if(check[x]){
			auto aa=coisas.lower_bound(mp(x,0));
			aa--;
			pair<int,int> xx=*aa;
			coisas.erase(xx);
			removeIntervalo(xx.f,xx.s);
			coisas.insert(mp(xx.f,x-1));
			coisas.insert(mp(x,xx.s));
			insereIntervalo(xx.f,x-1);
			insereIntervalo(x,xx.s);
		}
		else{
			auto aa=coisas.lower_bound(mp(x,0));
			aa--;
			pii xx1=*aa;
			pii xx2=*coisas.lower_bound(mp(x,0));
			coisas.erase(xx1);
			coisas.erase(xx2);
			removeIntervalo(xx1.f,xx1.s);
			removeIntervalo(xx2.f,xx2.s);
			coisas.insert(mp(xx1.f,xx2.s));
			insereIntervalo(xx1.f,xx2.s);
		}
		// /for(auto y:coisas)cout<<"a "<<y.f<<" "<<y.s<<endl;
		cout<<ans<<endl;
 
	}
 
 
 
	return 0;
}