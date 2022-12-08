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
#define INF INT_MAX;
#define MOD 1000000007

vector<int> vec;
vector<int> aux;


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	vec.pb(1);
	int fim=0;
	for(int i=0;i<10;i++){
		for(int j=fim;j<vec.size();j++){
			aux.pb(10*vec[j]);
			aux.pb(10*vec[j]+1);
		}
		fim=vec.size();
		for(int j=0;j<aux.size();j++){
			vec.pb(aux[j]);
		}
		aux.clear();
	}

	int resp=0;
	for(int i=0;i<vec.size();i++){
		//if(vec[i]<=10)cout<<vec[i]<<endl;
		if(vec[i]<=n)resp++;
	}

	cout<<resp<<endl;

	return 0;
}