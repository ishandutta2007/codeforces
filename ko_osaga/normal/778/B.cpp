#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int mod = 1e9 + 7;

int n, m;
string name[5555];
string a[5555], b[5555];
map<string, int> idx;

int opr[5555]; // 0 : empty 1 : xor 2 : or 3 : and

int trial(int pos, int bit){
	int ans[5555] = {};
	for(int i=1; i<=n; i++){
		if(opr[i] == 0){
			ans[i] = (a[i][pos] == '1');
		}
		else{
			int p1, p2;
			if(a[i] == "?") p1 = bit;
			else p1 = ans[idx[a[i]]];

			if(b[i] == "?") p2 = bit;
			else p2 = ans[idx[b[i]]];

			if(opr[i] == 1) ans[i] = p1 ^ p2;
			else if(opr[i] == 2) ans[i] = p1 | p2;
			else ans[i] = p1 & p2;
		}
	}
	return count(ans + 1, ans + n + 1, 1);
}

int main(){
	scanf("%d %d\n",&n,&m);
	for(int i=1; i<=n; i++){
		char t1[55] = {};
		char t2[55] = {};
		char t3[5555] = {};
		char t4[55] = {};
		char t5[55] = {};
		scanf("%s %s %s", t1, t2, t3);
		name[i] = t1;
		if(*t3 == '0' || *t3 == '1'){
			opr[i] = 0;
			a[i] = t3;
		}
		else{
			scanf("%s %s", t4, t5);
			a[i] = t3;
			b[i] = t5;
			if(*t4 == 'A') opr[i] = 3;
			else if(*t4 == 'X') opr[i] = 1;
			else opr[i] = 2;
		}
	}
	for(int i=1; i<=n; i++) idx[name[i]]= i;  
	string r1, r2;
	for(int i=0; i<m; i++){
		int x = trial(i, 0);
		int y = trial(i, 1);
		if(x < y){
			r1.push_back('0');
			r2.push_back('1');
		}
		if(x == y){
			r1.push_back('0');
			r2.push_back('0');
		}
		if(x > y){
			r1.push_back('1');
			r2.push_back('0');
		}
	}
	cout << r1 << endl << r2 << endl;
}