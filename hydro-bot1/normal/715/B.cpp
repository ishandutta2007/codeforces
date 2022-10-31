// Hydro submission #6181251f3901df1098454e84@1635853600611
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e18 + 1;
int n,m,l,s,t;
int id[N],cnt = 0;
struct node {
	int from,to,w;
} a[N];
struct ndoe {
	int to,next,w;
} tr[N];
int h[N],k = 0;
int d[N],vis[N],in[N];
queue<int> q;
void add(int from,int to,int w) {
	tr[++k].to = to;
	tr[k].next = h[from];
	tr[k].w = w;
	h[from] = k;
}
void spfa() {
	for(int i = 1 ; i <= n ; i ++) d[i] = INF,vis[i] = false,in[i] = 0;
	q.push(s),d[s] = 0,vis[s] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop(),vis[u] = false;
		for(int i = h[u] ; ~i ; i = tr[i].next) {
			int y = tr[i].to;
			if(d[y] > d[u] + tr[i].w) {
				d[y] = d[u] + tr[i].w;
				if(!vis[y]) {
					vis[y] = true;
					q.push(y);
					if(++ in[y] > N) return;
				}
			}
		}
	}
}
signed main() {
	memset(h,-1,sizeof(h));
	cin >> n >> m >> l >> s >> t;
	s++,t++;
	for(int i = 1 ; i <= m ; i ++) cin >> a[i].from >> a[i].to  >> a[i].w,a[i].from++,a[i].to++;
	for(int i = 1 ; i <= m ; i ++) {
		if(a[i].w == 0) {
			id[++cnt] = i;
		} else add(a[i].from,a[i].to,a[i].w),add(a[i].to,a[i].from,a[i].w);
	}
	spfa();
	if(d[t] < l) {
		cout << "No";
		return 0;
	} else if(d[t] == l) {
		cout << "Yes"<<endl;
		for(int i = 1 ; i <= m ; i ++) {
			cout << a[i].from - 1<<" "<< a[i].to - 1<<" ";
			if(a[i].w == 0) cout << INF - 1 << endl;
			else cout << a[i].w << endl;
		}
		return 0;
	} else if(d[t] > l) {
		for(int i = 1 ; i <= cnt ; i ++) {
			a[id[i]].w = 1;
			add(a[id[i]].from,a[id[i]].to,1),add(a[id[i]].to,a[id[i]].from,1);
			spfa();
			if(d[t] > l) continue;
			if(d[t] <= l) {
				cout << "Yes"<<endl;
				a[id[i]].w =  l - d[t] + 1;
				for(int i = 1 ; i <= m ; i ++) {
					cout << a[i].from - 1<<" " <<a[i].to - 1 <<" ";
					if(a[i].w == 0) cout <<INF - 1 << endl;
					else cout << a[i].w << endl;
				}
				return 0;
			}

		}
	}

	cout << "No";
	return 0;
}