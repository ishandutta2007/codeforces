#include<bits/stdc++.h>
using namespace std;
typedef long double db;
typedef long long ll;
const int N=1e6+5;
struct Dat{
	ll x,y,a;
	bool operator < (const Dat b)const {
		return x < b.x;
	}
}d[N];
int n;
struct Node{
	ll x,y;
	Node(ll x=0,ll y=0):x(x),y(y){}
	db operator * (Node b){
		return (db)y*b.x-(db)x*b.y;
	}
	Node operator - (Node b){
		return Node(x-b.x,y-b.y);
	}
};
Node q[N];int u=1,v;
ll f[N];

int main()
{
	cin >> n;
	f[0]=0;
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&d[i].x,&d[i].y,&d[i].a);
	sort(d+1,d+n+1);
	q[++v] = Node(0,0);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		while(u<v && Node(1,d[i].y)*(q[u+1]-q[u]) < 0)++u;
		f[i] = q[u].y - d[i].a + (d[i].x-q[u].x)*d[i].y;
		ans = max(ans, f[i]);
		Node newnd=Node(d[i].x,f[i]);
		while(u<v && (newnd-q[v-1])*(q[v]-q[v-1]) > 0)--v;
		q[++v]=newnd;
	}
	cout << ans << endl;
}