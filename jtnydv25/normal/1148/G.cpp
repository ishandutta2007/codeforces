#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int M = 1e7 + 10;
const int MAGIC = 205;
const int N = 1e5 + 10;
const int MAXP = 8;
const int FREQ = N * 8 / (double) MAGIC;

int invprime[M], factor[M];
bitset<N> bs[MAGIC];
int bitset_index[N * 10], freq[M];
vector<int> locations[N * 10];
int a[N];
vector<int> primes[N];
bitset<N> TOTAL, not_vis;

vector<vector<int> > components;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

void bfs(int s){
	queue<int> q;
	vector<int> comp;
	q.push(s);
	while(!q.empty()){
		int node = q.front();
		comp.push_back(node);
		q.pop();
		not_vis[node] = 0;
		bitset<N> bs_local = not_vis;
		for(int pi : primes[node]){
			int t = bitset_index[pi];
			if(t){
				bs_local &= bs[t]; 
			} else{
				for(auto it : locations[pi]){
					bs_local[it] = 0;
				}
			}
		}
		int curr = 0;
		while(1){
			curr = bs_local._Find_next(curr);
			if(curr == N) break;
			q.push(curr);
			not_vis[curr] = 0;
		}
	}
	components.push_back(comp);
}

int main(){
	for(int i = 2;i*i<M;i++) if(!factor[i]) for(int j = i*i;j<M;j+=i) factor[j] = i;
	int nump = 0;
    for(int i = 2;i<M;i++) if(!factor[i])  factor[i] = i;

    int n = 100000, k = 30000;
     sd(n); sd(k);
	TOTAL.flip();
	not_vis.flip();

	for(int i = 1; i <= n; i++){
		a[i] = 720720;
		sd(a[i]);
		int x = a[i];
		while(x > 1){
			int p = factor[x];
			// trace(x, p);
			while(x % p == 0){
				x /= p;
			}
			freq[p]++;
		}
	}
	for(int i = 0; i < MAGIC; i++) bs[i] = TOTAL;
	int bsi = 0;

	for(int i = 2; i < M; i++){
		if(freq[i]){
			invprime[i] = ++nump;
		}
		if(freq[i] > FREQ){
			bitset_index[nump] = ++bsi;
			trace(i);
		}
	}

	for(int i = 1; i <= n; i++){
		int x = a[i];
		while(x > 1){
			int p = factor[x];
			while(x % p == 0){
				x /= p;
			}
			int t = invprime[p];
			primes[i].push_back(t);
			if(bitset_index[t]) bs[bitset_index[t]][i] = 0;
			else{
				locations[t].push_back(i);
			}
		}
	}
	for(int i = n + 1; i < N; i++) not_vis[i] = 0;
	for(int i = 1; i <= n; i++) if(not_vis[i]){
		bfs(i);
	}

	vector<int> perm(components.size());
	for(int i = 0;i< perm.size(); i++) perm[i] = i;
	sort(perm.begin(), perm.end(), [&](int i, int j){return components[i].size() < components[j].size();});

	int num1 = 0, num2 = 0;
	for(int i = 0; i < components.size(); i++){
		if(components[i].size() == 1) num1++;
		else if(components[i].size() == 2) num2++;
	}

	if(2 * (num1 + num2)  >= n){
		for(int i = 0; i < k; i++){
			printf("%d ", components[perm[i]][0]);
		}
		return 0;
	}
	int req = k;
	vector<int> sol;
	int lst = -1;
	for(int j = 0; j < (int)components.size() && req; j++){
		int i = perm[j];
		if(components[i].size() >= 2){
			if(req == 1 && components[i].size() == 2) continue;
			else if(req > components[i].size()){
				for(auto it : components[i]){
					sol.push_back(it);
					req--;
				}
				lst = i;
				continue;
			}
			assert((int)components[i].size() != 1);
			if(req == 1){
				if(components[lst].size() == 2){
					sol.pop_back();
					sol.pop_back();
					req += 2;		
				} else{
					sol.pop_back();
					req ++;
				}
			}
			for(auto it : components[i]){
				if(req){
					sol.push_back(it);
					req--;
				}
			}
			break;
		}
	}
	assert(sol.size() == k);
	for(auto it : sol){
		printf("%d ", it);
	}
}