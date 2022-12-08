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

int vs[112345];
int vf[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int el,n;
	cin>>el>>n;

	int mini=INF;
	for(int i=0;i<n;i++){
		cin>>vs[i]>>vf[i];
		mini=min(vf[i]-vs[i]+1,mini);
	}
	cout<<mini<<endl;
	for(int i=0;i<el;i++){
		cout<<i%mini<<" ";
	}
	cout<<endl;


	return 0;
}