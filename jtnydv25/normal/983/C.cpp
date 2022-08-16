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

const int M = 2e6;

const int INF = 1e9 + 10;
const int STATES = 720;
const int N = 2005;
const int FLOORS = 10;

int mapping[M];
int invmapping[STATES];
int f[STATES][10];
int total[STATES];
int cnt = 0;

inline int getInd(int floor, int state){
	return floor * STATES + state;
}

vector<pii> con[FLOORS * STATES];
vector<int> states;

int a[N], b[N];
int n;
int dist[FLOORS * STATES];

const int GOAL = FLOORS * STATES - 1;

int pw[100];
int st[100];
int par[FLOORS * STATES];
void dijkstra(){
    priority_queue<pii,vector<pii>, greater<pii> > Q; 
    for(int i = 0; i < FLOORS * STATES; i++) dist[i] = INF;
    dist[GOAL] = 0;
    Q.push(pii(0,GOAL));
    while(!Q.empty()) {
        pii top = Q.top();
        Q.pop();
        int v = top.second, d = top.first;
        if(d <= dist[v]) {
            for(auto it : con[v]){
                int v2 = it.first, cost = it.second;
                if(dist[v2] > dist[v] + cost) {
                    dist[v2] = dist[v] + cost;
                    par[v2] = v;
                    Q.push(pii(dist[v2], v2));
                }
            }
        }
    }
}

void traceit(int state){
	while(state != GOAL){
		cerr << state << endl;
		state = par[state];
	}
}

int main(){
	pw[0] = 1;
	for(int i = 1; i < 100; i++) pw[i] = pw[i - 1] * 5;
	for(int i = 0; i < M; i++){
		int tot = 0;
		int I = i;
		int pos = 0;
		for(int j = 0; j < 9; j++){
			int newI = I / 5;
			int val = (I - newI * 5);
			st[pos++] = val;
			tot += val;
			I = newI;
		}

		if(tot <= 4 && I == 0){
			mapping[i] = ++cnt;
			invmapping[cnt] = i;
			// states.push_back(i);
			total[cnt] = tot;
			for(int j = 0; j < 9; j++) f[cnt][j] = st[j];
		}

	}

	sd(n);
	for(int i = 1; i <= n; i++) sd(a[i]), sd(b[i]), a[i]--, b[i]--;
	for(int i = 0; i < FLOORS * STATES; i++) dist[i] = INF;
	for(int currfloor = 0; currfloor < 9; currfloor++){
		for(int state = 1; state <= cnt; state++){
			int this_state = getInd(currfloor, state);
			if(currfloor != 8){
				int new_state = getInd(currfloor + 1, state);
				con[new_state].push_back({this_state, 1});
			}

			if(currfloor != 0){
				int new_state = getInd(currfloor - 1, state);
				con[new_state].push_back({this_state, 1});
			}
			if(f[state][currfloor]){
				int new_state = getInd(currfloor, mapping[invmapping[state] - pw[currfloor]]);
				con[new_state].push_back({this_state, 1});
			}

			if(total[state] == 0){
				con[GOAL].push_back({this_state, 0});
				// cerr << currfloor << " " << state << " " << this_state << endl;
			}
		}
	}

	dijkstra();
	// int mx = 0;
	// for(int i = 0; i < 8; i++)
	// 	for(int j = 1; j <= cnt; j++){
	// 		mx = max(mx, dist[getInd(i ,j)]);
	// 	}	
	// cerr << mx << endl;
	// cerr << dist[getInd(0, mapping[2])] << endl;
	for(int i = n; i >= 1; i--){
		for(int j = 0; j < FLOORS * STATES; j++) con[j].clear();
		int nxt = a[i], dst = b[i];
		for(int currfloor = 0; currfloor < 9; currfloor ++){
			for(int state = 1; state <= cnt; state++){
				int this_state = getInd(currfloor, state);
				if(currfloor == nxt && total[state] != 4){	
					// enter the lift
					int new_state = getInd(currfloor, mapping[invmapping[state] + pw[b[i]]]);
					if(dist[new_state] < INF) con[GOAL].push_back({this_state, dist[new_state] + 1});
				}
				if(currfloor != 8){
					int new_state = getInd(currfloor + 1, state);
					con[new_state].push_back({this_state, 1});
				}

				if(currfloor != 0){
					int new_state = getInd(currfloor - 1, state);
					con[new_state].push_back({this_state, 1});
				}
				if(f[state][currfloor]){
					int new_state = getInd(currfloor, mapping[invmapping[state] - pw[currfloor]]);
					con[new_state].push_back({this_state, 1});
				}
			}
		}

		dijkstra();
	}

	int ans = INF;
	// traceit(getInd(0, mapping[0]));
	// cerr << dist[getInd(0, mapping[0])] << endl;
	printf("%d\n", dist[getInd(0, mapping[0])]);
}