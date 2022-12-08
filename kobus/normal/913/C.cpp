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
#define INF LLONG_MAX
#define MOD 1000000007

int n,l;
int v[112];

int pd(int cara){

	if(cara<=0)return 0ll;

	ll bmc=INF;
	int bit=0;
	ll nbmc=INF;

	for(int i=30;i>=0;i--){
		if((cara>>i)%2==1){
			bit=i;
			break;
		}
	}

	for(int i=0;i<n;i++){
		if(i>bit)
			nbmc=min(nbmc,1ll*v[i]);
  		else
  			bmc=min(bmc,((1ll*v[i])<<(bit-i)));
	}

	bmc=bmc+pd(cara-(1ll<<bit));

	return min(bmc,nbmc);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

  	cin>>n>>l;
  	for(int i=0;i<n;i++){
  		cin>>v[i];
  	}

  	cout<<pd(l)<<endl;

  	return 0;

}