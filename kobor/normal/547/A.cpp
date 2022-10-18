//Krzysztof Boryczka
#pragma GCC optimize "O3"
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

const int N=1e6+5;

int m, rem, k1, k2, al1, al2;
int h1, a1, a11, x1, y11, b1, c1;
int h2, a2, a22, x2, y22, b2, c2;
int dist1[N], dist2[N];
bool vis1[N], vis2[N];

void solve(){
	cin>>m;
	cin>>h1>>a1>>x1>>y11;
	cin>>h2>>a2>>x2>>y22;
	while(!dist1[h1]){
		dist1[h1]=++c1;
		h1=((ll)x1*h1+y11)%m;
	}
	b1=dist1[a1]-1;
	if(b1==-1){
		cout<<-1<<ent;
		return;
	}
	c1=1;
	a11=a1;
	a11=((ll)x1*a11+y11)%m;
	while(a11!=a1){
		a11=((ll)x1*a11+y11)%m;
		c1++;
		if(c1>m){
			al1=1;
			break;
		}
	}
	// cout<<b1<<sp<<c1<<endl;

	while(!dist2[h2]){
		dist2[h2]=++c2;
		h2=((ll)x2*h2+y22)%m;
	}
	b2=dist2[a2]-1;
	if(b2==-1){
		cout<<-1<<ent;
		return;
	}
	c2=1;
	a22=a2;
	a22=((ll)x2*a22+y22)%m;
	while(a22!=a2){
		a22=((ll)x2*a22+y22)%m;
		c2++;
		if(c2>m){
			al2=1;
			break;
		}
	}
	// cout<<b2<<sp<<c2<<endl;

	if(al1 && al2){
		if(b1==b2) cout<<b1<<ent;
		else cout<<-1<<ent;
		return;
	}
	if(al1){
		k2=(b1-b2)/c2;
		if(k2>=0 && b1==(ll)k2*c2+b2) cout<<b1<<ent;
		else cout<<-1<<ent;
		return;
	}
	if(al2){
		k1=(b2-b1)/c1;
		if(k1>=0 && b2==(ll)k1*c1+b1) cout<<b2<<ent;
		else cout<<-1<<ent;
		return;
	}

	rem=((b2-b1)%c2+c2)%c2;
	while(!vis1[k1] && (ll)k1*c1%c2!=rem) vis1[k1++]=1;
	if(vis1[k1]) cout<<-1<<ent;
	else{
		k2=((ll)k1*c1+b1-b2)/c2;
		if(k2<0){
			k2=0;
			rem=((b1-b2)%c1+c1)%c1;
			while(!vis2[k2] && (ll)k2*c2%c1!=rem) vis2[k2++]=1;
			if(vis2[k2]) cout<<-1<<ent;
			else cout<<(ll)k2*c2+b2<<ent;
		}
		else cout<<(ll)k1*c1+b1<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}