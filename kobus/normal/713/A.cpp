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

int v[1123456];

int findnum(int a){
	int resp=0;
	int counter=0;
	while(a>0){
		resp+=((a%2)<<counter);
		a=a/10;
		counter++;
	}
	return resp;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin>>q;

	for(int i=0;i<q;i++){
		char c;
		cin>>c;
		int n;
		cin>>n;
		//cout<<findnum(n)<<endl;
		if(c=='+'){
			v[findnum(n)]++;
		}
		if(c=='-'){
			v[findnum(n)]--;
		}
		if(c=='?'){
			cout<<v[findnum(n)]<<endl;
		}
	}	

	return 0;
}