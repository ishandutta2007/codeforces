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

	int n,d;
	cin>>n>>d;
	int tot=n;
	vector<int> p(n);
	for(int i=0;i<n;i++)cin>>p[i];
	sort(p.begin(),p.end());
	int resp=0;
	for(int i=n-1;i>=0;i--){
		tot-=(d+p[i])/p[i];
		if(tot<0)break;
		resp++;
	}
	cout<<resp<<endl;

	
}