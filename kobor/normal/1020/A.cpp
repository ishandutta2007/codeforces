//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
const int INF=1e9+9;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)(x).size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
#define DEBUG(x) x
#define WATCH(x) cout<<(#x)<<" is "<<(x)<<ent

//END OF TEMPLATE

LL n, h, a, b;

LL dist(LL y1, LL y2){
	if((y1>b&&y2>b)){
		return y1-b+y2-b;
	}
	if((y1<a&&y2<a)){
		return a-y1+a-y2;
	}
	return max(y1, y2)-min(y1, y2);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	LL x1, y1, x2, y2;
	cin>>n>>h>>a>>b>>k;
	FOR(i, 1, k){
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2){
			cout<<max(y1, y2)-min(y1, y2)<<ent;
		}
		else{
			cout<<abs(x1-x2)+dist(y1, y2)<<ent;
		}
	}
	return 0;
}