#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define INF INT_MAX

int fib[1123];

int fibb(int n){
	if(fib[n]!=0)return fib[n];
	if(n==0||n==1)return fib[n]=1;
	return fib[n]=fibb(n-1)+fibb(n-2);
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		int sum=0;
		multiset<int> c;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			sum+=x;
			c.insert(x);
		}
		//cout<<"AAA"<<endl;
		int id=0;
		vector<int> vals;
		while(sum>0){
			sum-=fibb(id);
			vals.pb(fibb(id));
			id++;
		}
		if(sum<0){
			cout<<"NO"<<endl;
			continue;
		}
		int bad=0;
		reverse(vals.begin(),vals.end());
		int offset=-1;
		//cout<<"BBBB"<<endl;
		for(int i=0;i<id;i++){
			if(c.size()==0){
				bad=1;
				break;
			}
			int nxt=*c.rbegin();
			c.erase(c.find(nxt));
			if(nxt<vals[i]){
				bad=1;
				break;
			}
			nxt-=vals[i];
			if(offset!=-1)c.insert(offset);
			offset=nxt;
		}
		if(bad||offset!=0)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;

	}


}