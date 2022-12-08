#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000

pii v[1123];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	n--;

	for(int i=0;i<m;i++){
		cin>>v[i].f>>v[i].s;
		v[i].f--;v[i].s--;
	}
	int num=-1;
	bool isresp=0;

	for(int i=1;i<112;i++){
		bool respar=1;
		for(int j=0;j<m;j++){
			if(v[j].f/i!=v[j].s){
				respar=0;
			}
		}
		if(respar){
			if(num==-1){
				num=i;
				isresp=true;
			}
			else{
				if((n/i)!=(n/num))isresp=false;
			}
		}
	}

	if(isresp)cout<<(n/num)+1<<endl;
	else cout<<-1<<endl;




	return 0;
}