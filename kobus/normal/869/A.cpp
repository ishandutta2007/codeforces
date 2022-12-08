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
#define INF LLONG_MAX/4
#define MOD 1000000007

int v1[2123];
int v2[2123];


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	set<int> s;
	cin>>n;

	for(int i=0;i<n;i++){
		int y;cin>>y;
		s.insert(y);
		v1[i]=y;
	}
	for(int i=0;i<n;i++){
		int y;cin>>y;
		s.insert(y);
		v2[i]=y;
	}
	int resp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s.find(v1[i]^v2[j])!=s.end()){
				resp++;
			}
		}
	}

	if(resp%2==0)cout<<"Karen"<<endl;
	else cout<<"Koyomi"<<endl;



	return 0;
}