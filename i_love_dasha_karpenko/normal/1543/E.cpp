#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 7E4 + 7;
int label[DIM],tin[DIM],pos[DIM],col[DIM];
vector<int> G[DIM];
int popcount(int x){
    int ret = 0;
    while(x){
        ret+=x&1;
        x = x>>1;
    }
    return ret;
}
int lg(int num){
    int ret = -1;
    while(num){
        num = num>>1;
        ret++;
    }
    return ret;
}
int an(){
    int h;
    ++h;
    return h;
}
int solve() {
	int n;
	cin >> n;
	int cnt = 1 << (n - 1);

	for (int i = 1; i <= cnt * n; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

    label[0] = 0;
	queue<int> Q;
	int timer = 1;
	tin[0] = 1;
	for(int i = 0;i<cnt*2;++i)
	    col[i] = 0;
	for(int i = 0;i<n;++i){
	    label[G[0][i]] = 1<<i;
	    tin[G[0][i]] = ++timer;
	    Q.push(G[0][i]);
	}

	while(!Q.empty()){
	    int cur = Q.front();
	    Q.pop();
	    for(auto to:G[cur]){
	        if (tin[to]!=0 && tin[to]<tin[cur])
	            continue;
	        label[to]|=label[cur];
	        if (tin[to]==0)
	            tin[to] = ++timer,Q.push(to);
	    }
	}
	for(int i = 0;i<cnt*2;++i){
	    for(int bit = 0;bit<n;++bit){
	        if (i&(1<<bit))
	            col[i]^=bit;
	    }
	}

    for(int i = 0;i<cnt*2;++i)
        pos[label[i]] = i;
    for(int i = 0;i<cnt*2;++i)
        cout<<pos[i]<<' ';
    cout<<endl;
    if ((cnt*2)%n!=0)
        cout<<"-1\n";
    else{
        for(int i = 0;i<cnt*2;++i)
            cout<<col[label[i]]<<' ';
        cout<<endl;
    }
    for(int i = 0;i<cnt*2;++i){
        G[i].clear();
        pos[i] = 0;
        label[i] = 0;
        tin[i] = 0;
        col[i] = 0;
    }

	return 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--)
		assert(solve());
}