#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;
int prime[N];

vector<pair<int, int> > pairings;
bool done[N];
vector<int> vec;
void pre(int n){
	for(int i = 3; 2 * i <= n; i++){
		if(!prime[i]){
			vec.clear();
			int cnt = 0;
			for(int j = i; j <= n; j += i){
				if(!done[j]){
					if(j != 2 * i){
						cnt++;
						vec.push_back(j);
						done[j] = 1;
					}
					prime[j] = 1;
				}
			}
			if(cnt & 1){
					vec.push_back(2 * i);
					done[2 * i] = 1;
					cnt++;
			}
			for(int k = 0; k < cnt / 2; k ++){
				pairings.push_back({vec[k], vec[k + cnt / 2]});
			}
		}
	}
	int prev = 0;
	for(int i = 2; i <= n; i += 2){
		if(!done[i]){
			if(prev){
				pairings.push_back({prev, i});
				prev = 0;
			}
			else prev = i;
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	pre(n);
	printf("%d\n", (int) pairings.size());
	for(auto it : pairings) printf("%d %d\n",  it.F, it.S);
}