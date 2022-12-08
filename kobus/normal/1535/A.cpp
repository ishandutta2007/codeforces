#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1123;
#define mp make_pair
#define f first
#define s second

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int v[4];
		for(int i=0;i<4;i++){
			cin>>v[i];
		}
		int v1=max(v[0],v[1]);
		int v2=max(v[2],v[3]);
		sort(v,v+4);
		if(v1<v2)swap(v1,v2);
		if(v1==v[3] && v2==v[2])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;


	}

}