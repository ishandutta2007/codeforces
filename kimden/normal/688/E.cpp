#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MOD 1000000007
#define big 1000000

vector<int> c;
vector<vector<int>> v;

int main()
{
	int n,k;
	cin >> n >> k;
	c.resize(n,0);
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	sort(c.begin(),c.end());
	v.resize(k+1,vector<int>(k+1,0));
	v[c[0]][c[0]] = 1;
	v[c[0]][0] = 1;
	v[0][0] = 1;
	int q;
	for(int l = 1;l<n;l++){
		q = c[l];
		if(k<q){
			break;
		}
		for(int j=k;j>=0;j--){
			for(int i=k;i>=0;i--){
				if(v[i][j]==0){
					if(i>=q){
						if(j>=q){
							v[i][j] += v[i-q][j-q];
						}
						v[i][j] += v[i-q][j];
						v[i][j] = min(1,v[i][j]);
						if(j==0 && v[i][j]==1){
							j = 0;
						}
					}
				}
			}
		}
	}
	int cnt=0;
	vector<int> ans;
	for(int j=0;j<=k;j++){
		if(v[k][j]){
			cnt++;
			ans.push_back(j);
		}
	}
	cout << cnt << "\n";
	for(int i=0;i<ans.size();i++){
		if(i>0){
			cout << " ";
		}
		cout << ans[i];
	}
}