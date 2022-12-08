#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000
#define int long long

int v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	queue <int> q;
	for(int i=0;i<n;i++){
		cin>>v[i];
		q.push(v[i]);
	}
	if(k>=n-1){
		cout<<n<<endl;
		return 0;
	}
	int player1=q.front();
	q.pop();
	int wins=0;
	while(true){
		int lastwin=player1;
		int player2=q.front();
		q.pop();
		//cout<<player1<<" "<<player2<<endl;
		q.push(min(player1,player2));
		player1=max(player1,player2);
		if(player1==lastwin)wins++;
		else wins=1;
		if(wins==k)break;
	}

	cout<<player1<<endl;

	return 0;
}