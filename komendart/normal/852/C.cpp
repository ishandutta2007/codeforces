#include <bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define fi0(x) memset((x), 0, sizeof(x))
#define ins insert
#define era erase
#define ret return
#define cont continue
#define mk make_pair
#define X first
#define Y second

typedef long long int lint;

const int MAXN = 1e5 + 5;

int n;
int b[MAXN];
set<pair<int, int>, greater<pair<int, int> > > s;
int ans[MAXN];

int main(){
	//freopen("t.in", "r", stdin);
	scanf("%d", &n);
	F(i, 0, n)scanf("%d", &b[i]);
	F(i, 0, n){
		int j = (i + 1)%n;
		int delta = abs(n - b[i] - b[j]);
		s.ins(mk(delta, i));
	}
	int l = 0, r = n - 1;
	while(!s.empty()){
		int pos = s.begin()->Y;
		s.era(s.begin());
		int j = (pos + 1)%n;
		if(n - b[pos] > b[j]){ans[pos] = l++;}else{ans[pos] = r--;}
	}
	F(i, 0, n)printf("%d ", ans[i]);
}