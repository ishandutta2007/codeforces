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
#define MOD 1000000007
#define MAXN 512345


int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(2);

	int m,n;
	cin>>n>>m;
	if(n==1){
		cout<<max(m-1,0ll)<<endl;
	}
	else if(m==1){
		cout<<max(n-1,0ll)<<endl;
	}
	else{
		cout<<(long long)n*max(m-1,0ll)<<endl;
	}

	
}