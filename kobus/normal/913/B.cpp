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
#define MAXN 3123
#define INF INT_MAX/2
#define MOD 1000000007

int n;
vector<int> are[1123];
bool leaf[1123];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

  	cin>>n;
  	for(int i=2;i<=n;i++){
  		int pai;
  		cin>>pai;
  		are[pai].pb(i);
  	}
  	for(int i=1;i<=n;i++){
  		if(are[i].size()==0)leaf[i]=true;
  	}
  	for(int i=1;i<=n;i++){
  		int fl=0;
  		for(int j=0;j<are[i].size();j++){
  			if(leaf[are[i][j]])fl++;
  		}
  		if(!leaf[i] && fl<3){
  			cout<<"No"<<endl;
  			return 0;
  		}
  	}

  	cout<<"Yes"<<endl;



  	return 0;

}