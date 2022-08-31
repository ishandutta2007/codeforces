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
string get(int i, int j){
	string ret = "a1";
	ret[0] = 'a' + i;
	ret[1] = '1' + j;
	return ret;
}

vector<int> v = {7, 1, 2, 3, 4, 5, 6, 0};
vector<int> u = {0, 1, 2, 3, 4, 5, 6, 7};

bool done[8];

void get_second(int i, int & j, int & moves){
	memset(done, 0, sizeof done);
	cout << get(i, j) << " ";
	done[j] = 1;
	for(int t = 0; t < 8 && moves; t++) if(!done[v[t]]){
		j = v[t];
		moves--;
		done[j] = 1;
		cout << get(i, j) << " ";
	}
}

void get1(int j, int moves){
	memset(done, 0, sizeof done);
	cout << get(7, j) << " ";
	int cur = 0;
	done[j] = 1;
	moves--;
	for(int t = 0; t < 7 && moves; t++){
		if(!done[u[t]]){
			moves--;
			j = u[t];
			done[j] = 1;
			cout << get(7, j) << " ";
		}
	}
	cout << get(7, 7) << endl;
}

int main(){
	int n; cin >> n;
	int curr = 0;
	int j = 0;
	int moves = n - 2;
	int i;
	int maxp = -1;
	for(i = 0; i < 7;){
		if(moves >= 7){
			get_second(i, j, moves);		
			maxp = i;
			if(moves){
				moves--;
				i++;
			} else break;
		} else break;
	}
	moves += 2;
	if(i != 7){
		if(i > maxp) cout << get(i, j) << " ";
		moves--;
		i = 7;	
	}
	get1(j, moves);
}