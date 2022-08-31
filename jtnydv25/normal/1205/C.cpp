    #include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long
    #define sd(x) scanf("%d", &(x))
    #define pii pair<int, int>
    #define F first
    #define S second
    #define all(c) ((c).begin()), ((c).end())
    #define sz(x) ((int)(x).size())
    #define ld long double
     
    template<class T,class U>
    ostream& operator<<(ostream& os,const pair<T,U>& p){
    	os<<"("<<p.first<<", "<<p.second<<")";
    	return os;
    }
     
    template<class T,class U>
    ostream& operator<<(ostream& os,const map<T, U> & mp){
    	os << "{";
    	int i = 0;
    	for(auto it : mp){
    		if(i) os<<", ";
    		os << it;
    		i++;
    	}
    	os << "}";	
    	return os;
    }
     
    template<class T>
    ostream& operator <<(ostream& os,const vector<T>& v){
    	os<<"{";
    	for(int i = 0;i < (int)v.size(); i++){
    		if(i)os<<", ";
    		os<<v[i];
    	}
    	os<<"}";
    	return os;
    }
     
    #ifdef LOCAL
    #define cerr cout
    #else
    #endif
     
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
    int n;
    const int N = 1005;
    int A[N][N];
    int parity[N * N];
    int vis[N * N];
     
    int get_index(int i, int j){
    	return i * n + j;
    }
     
    pii get(int ind){
    	return {ind / n, ind % n};
    }
     
    int query(int p, int q){
    	if(p > q) swap(p, q);
    	pii P = get(p), Q = get(q);
    	// if(P > Q) swap(P, Q);
    	printf("? %d %d %d %d\n", P.F + 1, P.S + 1, Q.F + 1, Q.S + 1);
    	fflush(stdout);
    	int v;
    	sd(v);
    	return v;
    }
     
    int dx[6] = {2, -2, 0, 0, 1, -1};
    int dy[6] = {0, 0, -2, 2, 1, -1};
     
    void dfs(int i, int j, int par){
    	int ind = get_index(i, j);
    	vis[ind] = 1;
    	parity[ind] = par;
    	// trace(ind, par);
    	for(int dir = 0; dir < 6; dir++){
    		int x = i + dx[dir], y = j + dy[dir];
    		if(x < n && y < n && x >= 0 && y >= 0){
    			int ind2 = get_index(x, y);
    			if(!vis[ind2]){
    				int p;
    				if(dx[dir] + dy[dir] > 0){
    					p = query(ind, ind2);
    				} else{
    					p = query(ind2, ind);
    				}
     
    				dfs(ind2 / n, ind2 % n, par ^ p ^ 1);
    			}
    		}
    	}
    }
     
    // void go(int i)
     
    int main(){
    	sd(n);
    	dfs(0, 0, 1);
    	dfs(0, 1, 0);
     
    	vector<int> indices;
    	for(int i = 0; i < n; i++) indices.push_back(get_index(i, 0));
    	for(int i = 1; i < n; i++) indices.push_back(get_index(n - 1, i));
     
     
    	// for(int i = 0; i < n; i++){
    	// 	for(int j = 0; j < n; j++){
    	// 		cerr << parity[get_index(i, j)] << " ";
    	// 	}
    	// 	cerr << endl;
    	// }
    	// 2 * n - 2
    	// for(int i = 0; )
     
    	trace(indices);
     
    	bool done = false;
    	int invert = -1;
    	for(int i = 0; i + 2 < sz(indices) && !done; i += 2){
    		if(parity[indices[i]] == parity[indices[i + 2]]){
    			if(i - 2 >= 0 && parity[indices[i - 2]] != parity[indices[i]]){
    				if(parity[indices[i - 1]] == parity[ indices[i + 1] ]){
    					int _q = query(indices[i - 1], indices[i + 2]);
    					invert = (parity[indices[i - 1]] ^ parity[indices[i + 2]] ^ _q ^ 1);
    					break;
    				} else{
    					int _q = query(indices[i - 2], indices[i + 1]);
    					invert  = (parity[indices[i - 2]] ^ parity[indices[i + 1]] ^ _q ^ 1);
    					break;
    				}
    			}
     
    			if(i + 4 < sz(indices) && parity[indices[i + 4]] != parity[indices[i]]){
    				if(parity[indices[i + 1]] == parity[indices[i + 3]]){
    					int _q = query(indices[i], indices[i + 3]);
    					invert = (parity[indices[i]] ^ parity[indices[i + 3]] ^ _q ^ 1);
    					break;
    				} else{
    					int _q = query(indices[i + 1], indices[i + 4]);
    					invert  = (parity[indices[i + 1]] ^ parity[indices[i + 4]] ^ _q ^ 1);
    					break;
    				}
    			}
    		}
    	}
    	assert(invert != -1);
    	printf("!\n");
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			int v = parity[get_index(i, j)];
    			if((i + j) & 1) v ^= invert;
    			printf("%d", v);
    		}
    		printf("\n");
    	}
    	fflush(stdout);
    }