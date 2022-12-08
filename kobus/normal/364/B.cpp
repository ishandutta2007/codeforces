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

int v[51];
int n,d;
int memo[51][MAXN];

//maximo q posso gastar
//que cara to, quanto dinheiro falta
int dp(int i, int r){
	if(r<0)return -1*INF;
	if(i==n)return 0;
	if(memo[i][r]==-1){
		memo[i][r]=max(dp(i+1,r),v[i]+dp(i+1,r-v[i]));
	}
	return memo[i][r];
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>d;

	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<MAXN;j++)memo[i][j]=-1;
	}

	int num=d;
	int it=0;
	while(true){
		int y=dp(0,num);
		if(y+d==num)break;
		num=y+d;
		it++;
	}

	cout<<num-d<<" "<<it<<endl;

	return 0;
}