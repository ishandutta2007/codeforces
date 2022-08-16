#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;
int a[N], b[N], p1[N], p2[N], p[N];

multiset<int> bought;
ll dhanrashi;
vector<int> vec[N];
int curr = 0;
void add(int cost){
	if(dhanrashi >= cost){
		curr++;
		dhanrashi -= cost;
		bought.insert(-cost);
		return;
	}

	if(!bought.empty() && (*bought.begin() + cost < 0)){
		dhanrashi -= (*bought.begin() + cost);
		bought.erase(bought.begin());
		bought.insert(-cost);
	}
}

bool cmp(int i, int j){ return b[i] < b[j] || (b[i] == b[j] && i < j);}
int main(){
	int n, m;
	sd(n); sd(m);
	for(int i = 0; i < n; i++) sd(a[i]);
	for(int j = 0; j < m; j++) sd(b[j]), p1[j] = j;
	for(int j = 0; j < m; j++) sd(p[j]);
	sort(p1, p1 + m, cmp);
	stable_sort(b, b + m);
	
	int rgt = n - 1;
	for(int i = 0; i < m; i++){
		while(rgt >= 0 && a[rgt] < b[i]) rgt--;
		if(rgt >= 0) vec[rgt].pb(i);			
	}
	for(int i = 0; i < n; i++){
		dhanrashi += a[i];
		for(int k : vec[i]){
			int j = p1[k];
			add(p[j]);
		}
	}
	printf("%d\n", curr);
}