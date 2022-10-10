#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=100010;
struct node{
	int len,s;
}a[maxn];
node up(node a){
	a.s++;return a;
}
ll sum(node a){
	if(a.s>a.len)return 1e18;
	int l1=a.len/a.s,l2=a.len/a.s+1;
	int s2=a.len%a.s,s1=(a.len-s2*l2)/l1;
	return (ll)l1*l1*s1+(ll)l2*l2*s2;
}
bool operator<(node a,node b){
	return (sum(a)-sum(up(a))<sum(b)-sum(up(b)));
}
int i,j,k,n,m;
priority_queue<node>Q;
int main() {
	cin>>n>>m;
	for(i=1;i<=n;i++)a[i]={read(),1},Q.push(a[i]);
	while(n!=m){
		node t=Q.top();Q.pop();
		++t.s;Q.push(t);++n;
	}ll ans=0;
	while(!Q.empty())ans+=sum(Q.top()),Q.pop();
	cout<<ans<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}