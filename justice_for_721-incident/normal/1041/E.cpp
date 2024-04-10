#include<iostream>
#include<queue>
using namespace std;
int n;
int last=0;
int cnt[1001];
int sum=0;
vector<int>v[1001];
vector<int>d;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int a,b;
		cin >> a >> b;
		if(b!=n){
			cout << "NO\n";
			return 0;
		}
		cnt[a]++;
	}
	for(int i=1; i<n ;i++){
		if(sum+cnt[i]>i){
			cout << "NO\n";
			return 0;
		}
		if(cnt[i]==0){
			d.push_back(i);
			continue;
		}
		for(int j=1; j<cnt[i] ;j++){
			v[i].push_back(d.back());
			d.pop_back();
		}
		sum+=cnt[i];
	}
	cout << "YES\n";
	for(int i=1; i<n ;i++){
		if(cnt[i]==0) continue;
		int last=i;
		for(int j=0; j<v[i].size() ;j++){
			cout << last << ' ' << v[i][j] << '\n';
			last=v[i][j];
		}
		cout << last << ' ' << n << '\n';
	}
}