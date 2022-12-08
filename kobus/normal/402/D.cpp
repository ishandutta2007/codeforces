#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 5123
#define INF INT_MAX
#define MOD (1ll<<(32)) 
#define pii pair<int,int> 

int a[MAXN];
int sa[MAXN];
int gcda[MAXN];
int sgcda[MAXN];

int bp[MAXN];
set<int> bps;

int memo[MAXN][MAXN];

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int score(int i){
	int resp=0;
	int div=2;
	int curr=0;
	while(i!=1 && div*div<=i){
		if(i%div==0){
			if(div==bp[curr]){
				while(i%div==0){
					resp--;
					i=i/div;
				}
			}
			else{
				while(i%div==0){
					resp++;
					i=i/div;
				}
			}
		}
		if(div==bp[curr])curr++;
		div++;
	}
	if(i!=1){
		if(bps.find(i)!=bps.end())resp--;
		else resp++;
	}
	return resp;
}

int n;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[n-i-1];
	for(int i=0;i<m;i++)cin>>bp[i];
	for(int i=0;i<m;i++)bps.insert(bp[i]);
	for(int i=0;i<n;i++)sa[i]=score(a[i]);
	gcda[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)gcda[i]=gcd(gcda[i+1],a[i]);
	for(int i=0;i<n;i++){
		if(i!=0&&gcda[i]==gcda[i-1])sgcda[i]=sgcda[i-1];
		else sgcda[i]=score(gcda[i]);
	}

	for(int i=0;i<=n;i++){
		memo[n][i]=0;
	}
	for(int i=n-1;i>=0;i--){
		int last=0;
		memo[i][last]=sa[i]+memo[i+1][last];
		memo[i][last]=max(memo[i][last],sa[i]-sgcda[i]+memo[i+1][i+1]);
		for(last=1;last<=i;last++){
			memo[i][last]=max(sa[i]-sgcda[last-1]+memo[i+1][last],
					sa[i]-sgcda[i]+memo[i+1][i+1]);
		}
	}

	cout<<memo[0][0]<<endl;

		

	return 0;
}