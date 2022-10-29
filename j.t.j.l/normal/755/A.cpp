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


std::vector<int> pl, mp, sq, nico;
void fast_sieve(int n) {
  pl.clear();
  mp.assign(n, 0);
  for (int i = 2; i < n; ++i) {
    if (!mp[i]) {
      pl.push_back(i);
      mp[i] = i;
    }
    for (size_t j = 0; j < pl.size() && i * pl[j] < n; ++j) {
      int p = pl[j];
      mp[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

void solve(int casi){
	cin>>n;
	fast_sieve(2000000);
	for(int m = 1; m <= 1000; m++){
		if (mp[n*m+1]!=n*m+1){
			cout<<m<<endl;
			return ;
		}
	}
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