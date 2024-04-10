#include<bits/stdc++.h>

using namespace std;

map<int,int>mp;

typedef long long ll;
typedef pair<int, ll> PIL;

const int MAXN = 3e3 + 10;

int n;
int a[MAXN];
int g[MAXN];

int ptQ[MAXN];
PIL Q[MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i] -= i;
		mp[a[i]] = 0;
	}
	int m = 0;
	for(auto i = mp.begin(); i != mp.end(); i++){
		i->second = ++m;
		g[m] = i->first;
	}
	for(int i = 1; i <= n; i++){
//		cout<<a[i]<<' '; 
		a[i] = mp[a[i]];
	}
/*	cout<<endl;
	for(int i = 1; i <= n; i++)
		cout<<a[i]<<' '; cout<<endl;
*/	for(int i = m; i >= 1; i--){
		ll cost = abs(g[i] - g[a[1]]);
		while(ptQ[1] > 0 && Q[1][ptQ[1]].second >= cost)
			ptQ[1]--;
		Q[1][++ptQ[1]] = PIL(i, cost);
	}
/*
	cout<<"====================="<<endl<<ptQ[1]<<endl;
	for(int i = 1; i <= ptQ[1]; i++)
		cout<<Q[1][i].first<<' '; cout<<endl;
	for(int i = 1; i <= ptQ[1]; i++)
		cout<<Q[1][i].second<<' '; cout<<endl;
	cout<<"###############"<<endl;
*/
	for(int i = 2; i <= n; i++){
		int pt = 1;
		for(int j = m; j >= 1; j--){
			while(pt <= ptQ[i-1] && Q[i-1][pt].first > j)
				pt++;
			ll cost;
			if (pt > ptQ[i-1]){
				cost = Q[i-1][ptQ[i-1]].second + (i-1) * (g[Q[i-1][ptQ[i-1]].first] - g[j]) + abs(g[j] - g[a[i]]);
			}
			else{
				cost = Q[i-1][pt].second + abs(g[j] - g[a[i]]);
			}
//			cout<<j<<' '<<pt<<' '<<cost<<endl;
			while(ptQ[i] > 0 && Q[i][ptQ[i]].second >= cost)
				ptQ[i]--;
			Q[i][++ptQ[i]] = PIL(j, cost);
		}
/*		cout<<"================="<<endl<<ptQ[i]<<endl;
		for(int j = 1; j <= ptQ[i]; j++)
			cout<<Q[i][j].first<<' '; cout<<endl;
		for(int j = 1; j <= ptQ[i]; j++)
			cout<<Q[i][j].second<<' '; cout<<endl;
		cout<<"###############"<<endl;
*/	}
	

	printf("%lld\n", Q[n][1].second);
	return 0;
}