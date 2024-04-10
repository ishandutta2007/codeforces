#include<bits/stdc++.h>
using namespace std;

const int _ = 5e5 + 7; map < int , int > vl; int N , T;
#define lowbit(x) ((x) & -(x))
int mx[_]; void clear(){for(int i = 1 ; i <= N ; ++i) mx[i] = 0;}
void mdf(int x , int v){while(x <= N){mx[x] = max(mx[x] , v); x += lowbit(x);}}
int qry(int x){int v = 0; while(x){v = max(v , mx[x]); x -= lowbit(x);} return v;}

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		clear(); vl.clear(); cin >> N; int ans = 0 , premx = 0;
		for(int i = 1 ; i <= N ; ++i){
			int v; cin >> v; int len = max((int)(premx > v) , qry(v)) + 1; premx = max(premx , v);
			while(vl.size() && vl.begin()->first <= v){
				len = max(len , vl.begin()->second + 1); mdf(vl.begin()->first , vl.begin()->second + 1); vl.erase(vl.begin());
			}
			ans = max(ans , len); vl[v] = len;
		}
		cout << ans << endl;
	}
	return 0;
}