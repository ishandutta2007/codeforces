#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define int ll
const int N = 1e3+7;
const int MX = 2e9;
int d[2][N];
void solve(){
	int n;
	cin>>n;
	set<int> V[2];
	vector<pair<int,int> > un;
	for(int c = 0;c<2;c+=1){
		for(int i = 1;i<=n;i+=1){
			cin>>d[c][i];
			V[c].insert(d[c][i]);
			un.push_back({d[c][i],c});
		}
	}
	sort(un.begin(),un.end(),greater<pair<int,int>>());
	for(int i = 1;i<=n;i+=1){
		for(int sg = -1;sg<=1;sg+=2){
			int dif = d[1][1]+sg*d[0][i];
//			cout<<dif<<endl;
			vector<int> S;
			int p[] = {0,dif};
			bool flag = 0;
			map<int,int> M[2],del[2];
			for(int c = 0;c<2;c+=1)
			for(int j = 1;j<=n;j+=1){
				M[c][d[c][j]] += 1;
			}
			for(auto [dst,col]:un){
				if (del[col][dst]>0){
					del[col][dst] -= 1;
					continue;
				}
				if (M[col^1][abs(p[col]+dst-p[col^1])]!=0){
					S.push_back(p[col]+dst);
					M[col^1][abs(p[col]+dst-p[col^1])] -= 1;
					del[col^1][abs(p[col]+dst-p[col^1])] += 1;
				}
				else if (M[col^1][abs(p[col]-dst-p[col^1])]!=0){
					S.push_back(p[col]-dst);
					M[col^1][abs(p[col]-dst-p[col^1])] -= 1;
					del[col^1][abs(p[col]-dst-p[col^1])] += 1;
				}
				else{
					flag = 1;
					break;
				}
				M[col][dst] -= 1;
			}
//		cout<<flag<<' '<<dif<<' '<<S.size()<<endl;
			if (flag){
				continue;
			}
			sort(S.begin(),S.end());
			int add = max({-p[0],-p[1],-*S.begin()});
			if (S.back()+add<=MX && p[0]+add<=MX && p[1]+add<=MX){
				cout<<"YES\n";
				for(int to:S){
					cout<<to+add<<' ';
				}
				cout<<endl<<p[0]+add<<' '<<p[1]+add<<endl;
				return;
			}
		}
	}
	cout<<"NO\n";

}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}