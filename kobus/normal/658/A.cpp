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

pii v[1123];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,c;
	cin>>n>>c;

	for(int i=0;i<n;i++){
		cin>>v[i].f;
	}
	for(int i=0;i<n;i++){
		cin>>v[i].s;
	}

	int ap=0;
	int at=0;
	for(int i=0;i<n;i++){
		at+=v[i].s;
		ap+=max(v[i].f-(c*at),0ll);
	}

	int bp=0;
	int bt=0;
	for(int i=n-1;i>=0;i--){
		bt+=v[i].s;
		bp+=max(v[i].f-(c*bt),0ll);
	}
	if(ap>bp){
		cout<<"Limak"<<endl;
	}
	else if(ap==bp){
		cout<<"Tie"<<endl;
	}
	else{
		cout<<"Radewoosh"<<endl;
	}
	


	return 0;
}