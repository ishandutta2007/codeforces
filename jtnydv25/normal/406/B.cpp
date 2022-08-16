#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

int came[1 << 20];
vector<int> solution;
inline int complement(int x){
	return 1000001 - x;
}
int main(){
	int s = 1000000;
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		int x;
		sd(x);
		came[x] = 1;
	}
	int curr = 1;
	for(int i = 1; i <= 500000; i++){
		if(came[i] && !came[complement(i)]){
			solution.push_back(complement(i));
			came[complement(i)] = 1;
		}
		else if(!came[i] && came[complement(i)]){
			solution.push_back(i);
			came[i] = 1;
		}
		else if(came[i] && came[complement(i)]){
			while(came[curr] || came[complement(curr)])
				curr++;
			// cerr << "curr = " << curr << endl;
			solution.push_back(curr);
			solution.push_back(complement(curr));
			curr++;
		}
	}
	printf("%d\n", (int)solution.size());
	for(int v : solution) printf("%d ", v);
	printf("\n");
}