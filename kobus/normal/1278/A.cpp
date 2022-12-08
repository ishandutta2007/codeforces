#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123
#define INF LLONG_MAX
#define MOD 1000000007 
#define pii pair<int,int> 
#define int long long



 
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);


 	int t;
 	cin>>t;
 	while(t--){
 		string a,b;
 		cin>>a>>b;
 		multiset<char> as;
 		for(char c:a)as.insert(c);
 		multiset<char> bs;
 		bool top=0;
 		for(int i=0;i<b.size();i++){
 			bs.insert(b[i]);
 			if(i>=a.size())bs.erase(bs.find(b[i-a.size()]));
 			if(as==bs)top=1;
 		}
 		if(top)cout<<"YES"<<endl;
 		else cout<<"NO"<<endl;
 	}

	return 0;
}