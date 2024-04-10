#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 3;
int N , Q; map < char , int > to; char str[_];
struct BIT{
	int arr[_];
#define lowbit(x) ((x) & -(x))
	void add(int x , int num){while(x <= N){arr[x] += num; x += lowbit(x);}}
	int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);}return sum;}
}val[3]; set < int > plc[3];

int calc(){
	int ans = 0;
	for(int i = 0 ; i < 3 ; ++i)
		if(plc[(i + 2) % 3].empty()) ans += plc[i].size();
		else if(!plc[(i + 1) % 3].empty()){
			int pb = *plc[(i + 1) % 3].begin() , pe = *--plc[(i + 1) % 3].end();
			int qb = *plc[(i + 2) % 3].begin() , qe = *--plc[(i + 2) % 3].end();
			ans += plc[i].size() - (pb > qb ? val[i].qry(pb) - val[i].qry(qb) : 0) - (pe < qe ? val[i].qry(qe) - val[i].qry(pe) : 0);
		}
	return ans;
}

int main(){
	to['R'] = 0; to['S'] = 1; to['P'] = 2; scanf("%d %d" , &N , &Q);
	scanf("%s" , str + 1); for(int i = 1 ; i <= N ; ++i){plc[to[str[i]]].insert(i); val[to[str[i]]].add(i , 1);}
	printf("%d\n" , calc());
	while(Q--){
		int x; scanf("%d" , &x); char c = getchar(); while(!isupper(c)) c = getchar();
		plc[to[str[x]]].erase(x); val[to[str[x]]].add(x , -1);
		plc[to[str[x] = c]].insert(x); val[to[c]].add(x , 1);
		printf("%d\n" , calc());
	}
	return 0;
}