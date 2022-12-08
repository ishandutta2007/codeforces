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
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	set<int> s;

	for(int i=0;i<n;i++){
		int y;cin>>y;
		s.insert(y);
	}

	int num=1;
	int maux=m;
	int resp=0;
	while(true){
		if(s.find(num)==s.end()){
			maux-=num;
			if(maux>=0)resp++;
			else break;
		}
		num++;
	} 
	num=1;
	cout<<resp<<endl;
	while(true){
		if(s.find(num)==s.end()){
			m-=num;
			if(m>=0)cout<<num<<" ";
			else break;
		}
		num++;
	} 
	cout<<endl;


	return 0;
}