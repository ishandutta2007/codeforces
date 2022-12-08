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

int vi[3];
int vr[3];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(11);
  	cout.setf(ios::fixed);

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>vi[j];
			vr[j]+=vi[j];
		}
	}

	if(vr[0]==0 && vr[1]==0 && vr[2]==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}