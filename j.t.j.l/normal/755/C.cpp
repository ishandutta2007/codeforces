#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){
	
}

int fa[MAXN];

int getfather(int x){
	return fa[x] == x ? x : fa[x] = getfather(fa[x]);
}

int a[MAXN];

void solve(int casi){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		int p = getfather(i);
		int q = getfather(a[i]);
		if (p != q){
			fa[p] = q;
		}
	}
	for(int i = 1; i <= n; i++)
		fa[i] = getfather(i);
	set<int> s;
	for(int i = 1; i <= n; i++)
		s.insert(fa[i]);
	cout<<s.size()<<endl;
}

void printans(){

}


int main(){
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}