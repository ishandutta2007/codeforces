#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;

#define int long long
const int _ = 2003;
struct Edge{int s , t , w;}Ed[_ * _];
bool operator <(Edge p , Edge q){return p.w < q.w;}
int fa[_] , N , M , x[_] , y[_] , k[_] , cnt;
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

signed main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i) cin >> x[i] >> y[i];
	for(int i = 1 , c ; i <= N ; ++i){
		cin >> c; Ed[++cnt] = (Edge){0 , i , c};
	}
	for(int i = 1 ; i <= N ; ++i) cin >> k[i];
	for(int i = 1 ; i <= N ; ++i)
		for(int j = i + 1 ; j <= N ; ++j)
			Ed[++cnt] = (Edge){i , j , (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
	sort(Ed + 1 , Ed + cnt + 1);
	for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	int ans = 0;
#define PII pair < int , int >
	vector < int > id1; vector < PII > id2;
	for(int i = 1 ; i <= cnt ; ++i)
		if(find(Ed[i].s) != find(Ed[i].t)){
			fa[find(Ed[i].s)] = Ed[i].t;
			if(Ed[i].s == 0) id1.push_back(Ed[i].t);
			else id2.push_back(PII(Ed[i].s , Ed[i].t));
			ans += Ed[i].w;
		}
	cout << ans << endl;
	cout << id1.size() << endl;
	for(auto t : id1) cout << t << ' ';
	cout << endl;
	cout << id2.size() << endl;
	for(auto t : id2)
		cout << t.first << ' ' << t.second << endl;
	return 0;
}