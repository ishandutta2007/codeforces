#include <bits/stdc++.h>
using namespace std;
const int N = 2005;	
int p[N];
map<int, vector<int> > mp;
int cntpos[N], cntneg[N];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];	
		mp[-abs(p[i])].push_back(i);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int pos = abs(p[i]);
			int neg = -abs(p[i]);
			if(abs(p[i]) > abs(p[j])){
				if(j < i && p[j] > pos) cntpos[i]++;
				if(j < i && p[j] > neg) cntneg[i]++;
				if(j > i && p[j] < pos) cntpos[i]++;
				if(j > i && p[j] < neg) cntneg[i]++;
			}
		}
	}
	int inv = 0;
	for(int i = 1; i <= n; i++) inv += min(cntpos[i], cntneg[i]); 
	/*for(auto it : mp){
		vector<int> vec = it.second;
		int m = vec.size();
		for(int l = 0; l < m; l++){

		}
	}*/
	printf("%d\n", inv);
}