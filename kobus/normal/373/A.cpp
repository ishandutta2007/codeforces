#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int v[10];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

  	int k;
  	cin>>k;
  	k=2*k;

  	for(int i=0;i<16;i++){
  		char c;
  		cin>>c;
  		if(c!='.'){
  			//cout<<c-'0'<<endl;
  			v[c-'0']++;
  		}
  	}

  	for(int i=0;i<10;i++){
  		//cout<<v[i]<<endl;
  		if(v[i]>k){
  			cout<<"NO"<<endl;
  			return 0;
  		}
  	}

  	cout<<"YES"<<endl;


	return 0;
}