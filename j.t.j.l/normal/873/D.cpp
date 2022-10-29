#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, k;
int a[MAXN];

void prework(){

}

void read(){

}

void gao(int l, int r){
	if (l + 1 >= r){
		return ;
	}
	int m = (l + r) / 2;
	if (k > 0 && l != m){
		k -= 2;
		swap(a[m - 1], a[m]);			
		gao(l, m);
		gao(m, r);
	}
}

int umi;

void check(int l, int r){
	umi--;
	int flag = 1;
	for (int i = l; i < r - 1; i++)
		if (a[i] > a[i + 1])
			flag = 0;
	if (flag)
		return ;
	int m = (l + r) / 2;
	check(l, m);
	check(m, r);
	sort(a + l, a + r);
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d", &n, &k);
	umi = k;
	k--;
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	gao(0, n);
	if (k != 0)
		puts("-1");
	else{
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], " \n"[i == n - 1]);
		
		/*check(0, n);
		cerr << umi << endl;
		assert(umi == 0);*/
	}
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
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