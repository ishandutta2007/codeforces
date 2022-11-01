#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ll long long
const int _ = 2e5 + 7; int N , Q , ans , K[_] , out[_]; ll sum[_];
priority_queue < pair < int , int > > heap; map < int , int > seg;

int main(){
	N = read(); Q = read(); for(int i = 1 ; i <= N ; ++i) sum[i] = sum[i - 1] + read();
	for(int i = 1 ; i <= Q ; ++i) K[i] = read();
	for(int i = 1 ; i <= N ; ++i){seg[i] = i; heap.push(make_pair(sum[i] - sum[i - 1] - 1 , i));}
	for(int i = Q ; i ; --i){
		while(!heap.empty() && heap.top().first >= K[i]){
			int t = heap.top().second; auto p = seg.find(t); heap.pop();
			if(p == seg.end() || sum[p->second] - sum[p->first - 1] <= 1ll * K[i] * (p->second - p->first + 1)) continue;
			auto q = p; ++q;
			while(sum[p->second] - sum[p->first - 1] > 1ll * K[i] * (p->second - p->first + 1) && q != seg.end()){p->second = q->second; seg.erase(q++);}
			ans = max(ans , p->second - p->first);
			if(p->second != N) heap.push(make_pair((sum[p->second] - sum[p->first - 1] - 1) / (p->second - p->first + 1) , p->first));
		}
		out[i] = ans;
	}
	for(int i = 1 ; i <= Q ; ++i) printf("%d " , out[i]);
	return 0;
}