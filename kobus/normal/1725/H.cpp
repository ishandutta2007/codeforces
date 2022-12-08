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

	int n;
	cin>>n;
	vector<int> st(n);
	for(int i=0;i<n;i++)cin>>st[i];
	int n0=0,n1=0;
	for(int i=0;i<n;i++){
		if(st[i]%3==0)n0++;
		else n1++;
	}
	if(n0>=n/2){
		int nn0=n/2;
		int nn1=n/2;
		cout<<2<<endl;
		for(int i=0;i<n;i++){
			if(st[i]%3==0 && nn0>0){
				cout<<0;
				nn0--;
			}
			else cout<<1;
		}
		cout<<endl;
	}
	else if(n1>=n/2){
		int nn0=n/2;
		int nn1=n/2;
		cout<<0<<endl;
		for(int i=0;i<n;i++){
			if(st[i]%3!=0 && nn1>0){
				cout<<0;
				nn1--;
			}
			else cout<<1;
		}
		cout<<endl;
	}
	
}