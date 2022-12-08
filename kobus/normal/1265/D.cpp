#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123
#define INF LLONG_MAX
#define MOD 32416187567
#define pii pair<int,int> 
#define int long long

int qt[4];
int qtt[4];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>qt[0]>>qt[1]>>qt[2]>>qt[3];
	int sum=0;
	for(int i=0;i<4;i++)sum+=qt[i];
	for(int i=0;i<4;i++){
		if(qt[i]==0)continue;
		vector<int> ans;
		for(int j=0;j<4;j++)qtt[j]=qt[j];
		qtt[i]--;
		ans.pb(i);
		int last=i;
		while(ans.size()<sum){
			if(last!=0 && qtt[last-1]>0){
				qtt[last-1]--;
				ans.pb(last-1);
				last=last-1;
			}
			else if(last!=3 && qtt[last+1]>0){
				qtt[last+1]--;
				ans.pb(last+1);
				last=last+1;
			}
			else break;
		}
		if(ans.size()==sum){
			cout<<"YES"<<endl;
			for(auto x:ans)cout<<x<<" ";
			cout<<endl;
			return 0;
		}
	}

	cout<<"NO"<<endl;




	return 0;
}