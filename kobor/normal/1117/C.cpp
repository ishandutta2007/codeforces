//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int N=100010;

ll xx1, yy1, xx2, yy2, l, r, dx, dy, mid;
ll prefx[N], prefy[N];
int fck;
string s;

bool check(ll days){
	ll presx, presy, newx, newy;
	presx=(days/fck)*dx + prefx[days%fck];
	presy=(days/fck)*dy + prefy[days%fck];
	newx=xx1+presx;
	newy=yy1+presy;
	return abs(newx-xx2)+abs(newy-yy2)<=days;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>xx1>>yy1>>xx2>>yy2;
	cin>>fck>>s;
	FOR(i, 0, SIZE(s)-1){
		prefx[i+1]=prefx[i];
		prefy[i+1]=prefy[i];
		if(s[i]=='R'){
			prefx[i+1]++;
		}
		if(s[i]=='L'){
			prefx[i+1]--;
		}
		if(s[i]=='U'){
			prefy[i+1]++;
		}
		if(s[i]=='D'){
			prefy[i+1]--;
		}
	}
	dx=prefx[fck];
	dy=prefy[fck];
	l=0; r=1e18+3;
	if(!check(r)){
		cout<<-1<<ent;
		return 0;
	}
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	cout<<r<<ent;
	return 0;
}