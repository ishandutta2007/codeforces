#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF LLONG_MAX;
#define MOD 1000000

int v[11];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		char y;
		cin>>y;
		int num=y-'0';
		if(num==2||num==3||num==5||num==7){
			v[num]++;
		}
		if(num==4){
			v[2]+=2;v[3]++;
		}
		if(num==6){
			v[3]++;v[5]++;
		}
		if(num==8){
			v[2]+=3;
			v[7]++;
		}
		if(num==9){
			v[3]+=2;
			v[2]++;
			v[7]++;
		}
	}
	for(int i=9;i>=2;i--){
		while(v[i]!=0){
			cout<<i;
			v[i]--;
		}
	}
	cout<<endl;

	return 0;
}