#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123456
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define double long double 
#define int long long

int fat[MAXN];
																																																																																	

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	fat[0]=1;
	for(int i=1;i<=n;i++)fat[i]=(fat[i-1]*i)%m;
	int resp=0;
	for(int i=1;i<=n;i++){
		//intervalos*maneiras de escolher*permutar
		resp+=((((n-i+1)*(n-i+1))%m)*((fat[i]*fat[n-i])%m))%m;
		resp%=m;
	}
	cout<<resp<<endl;

	
	return 0;
}