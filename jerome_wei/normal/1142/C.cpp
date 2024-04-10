#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+5;
struct Node{
	ll x,y;
	Node(ll x = 0,ll y = 0) : x(x), y(y) {}
	long double operator * (const Node b)const{
		return (long double)y*b.x - (long double)x*b.y;
	}
	Node operator - (const Node b)const{
		return Node(this->x - b.x,this->y - b.y);
	}
	bool operator < (const Node b) const {
		return x==b.x ? y<b.y : x < b.x;
	}
}t[N];
int n;
Node stk[N];int top;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		ll x,y;cin >> x >> y;
		t[i] = Node(x,y-x*x);
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++){
		if(t[i].x == t[i+1].x && i!=n) continue;
		while(top>=2 && 0 >= (stk[top]-stk[top-1]) * (t[i]-stk[top-1]))--top;
		stk[++top] = t[i];
		// for(int i=1;i<=top;i++)cout<<"["<<stk[i].x <<" , " <<stk[i].y<<"]";puts("");
	}
	cout << top-1 << endl;
	return 0;
}