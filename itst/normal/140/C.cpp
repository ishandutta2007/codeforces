#include<bits/stdc++.h>
using namespace std;

#define PII pair < int , int >
struct man{int a , b , c;}; vector < man > ans;
priority_queue < PII > q; map < int , int > cnt; int N;

int main(){
	cin >> N;
	for(int x , i = 1 ; i <= N ; ++i){cin >> x; ++cnt[x];}
	for(auto t : cnt) q.push(PII(t.second , t.first));
	while(q.size() >= 3){
		vector < PII > now;
		for(int i = 0 ; i < 3 ; ++i){now.push_back(q.top()); q.pop();}
		sort(now.begin() , now.end() , [&](PII a , PII b){return a.second > b.second;});
		ans.push_back((man){now[0].second , now[1].second , now[2].second});
		for(int i = 0 ; i < 3 ; ++i) if(--now[i].first) q.push(now[i]);
	}
	cout << ans.size() << endl;
	for(auto t : ans) cout << t.a << ' ' << t.b << ' ' << t.c << endl;
	return 0;
}