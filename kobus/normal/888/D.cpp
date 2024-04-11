#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007
#define int long long


int resp[5];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	resp[1]=1;

	resp[2]=(n*(n-1))/2;
	resp[2]+=resp[1];

	resp[3]=(n*(n-1)*(n-2))/3;
	resp[3]+=resp[2];

	resp[4]=((n*(n-1)*(n-2)*(n-3))/24)*9;
	resp[4]+=resp[3];

	cout<<resp[k]<<endl;

	return 0;
}