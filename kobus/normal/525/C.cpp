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

int v[112345];

bool rev(int a,int b){
	return a>b;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	sort(v,v+n,rev);

	int fp=-1;
	int sp=-1;

	int resp=0;

	for(int i=0;i<n-1;i++){
		if(v[i]==v[i+1]||v[i]==v[i+1]+1){
			if(fp==-1)fp=v[i+1];
			else{
				sp=v[i+1];
				resp+=fp*sp;
				fp=-1;sp=-1;
			}
			i++;
		}
	}
	cout<<resp<<endl;

	return 0;
}