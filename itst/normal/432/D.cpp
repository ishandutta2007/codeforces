#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;

const int _ = 1e5 + 7; char str[_]; int z[_] , L , sum[_];
#define PII pair < int , int >
vector < PII > ans;

int main(){
	scanf("%s" , str + 1); L = strlen(str + 1);
	int mx = 0 , id = 1; z[1] = L; ++sum[L];
	for(int i = 2 ; i <= L ; ++i){
		if(mx < i) mx = i;
		z[i] = min(mx - i , z[i - id + 1]);
		while(str[z[i] + i] == str[z[i] + 1]) ++z[i];
		if(i + z[i] > mx){mx = z[i] + i; id = i;}
		++sum[z[i]];
	}
	for(int i = L ; i ; --i) sum[i] += sum[i + 1];
	for(int i = 1 ; i <= L ; ++i)
		if(z[L - i + 1] == i) ans.push_back(make_pair(i , sum[i]));
	cout << ans.size() << endl;
	for(auto t : ans) cout << t.first << ' ' << t.second << endl;
	return 0;
}