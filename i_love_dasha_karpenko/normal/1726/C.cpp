//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
const int N = 2e5+7;
int A[N],P[N];
int F(int x){
	return x==P[x]?x:P[x] = F(P[x]);
}
bool unite(int a,int b){
	a = F(a);
	b = F(b);
	if (a==b){
		return 0;
	}
	P[a] = b;
	return 1;
}
void solve(){
	int n;
	cin>>n;
	n*=2;
	for(int i = 1;i<=n;i+=1){
		char ch;
		cin>>ch;
		A[i] = (ch=='('?1:-1);
		P[i] = i;
	}
	stack<int> clz;
	int sum = 0,cmp = n;
	for(int i = 1;i<=n;i+=1){
		sum += A[i];
		if (A[i]==1){
			clz.push(i);
		}
		else{
			int op = clz.top();
			clz.pop();
			cmp -= unite(i,op);
			if (op!=1 && A[op-1]==-1){
				cmp -= unite(op,op-1);
			}
		}
	}
	cout<<cmp<<endl;
}
signed main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
	cin>>tt;
	while(tt--){
		solve();
	}
}