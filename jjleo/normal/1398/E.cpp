#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

set<int> st[3];
int x;

int n;
int tp, d;
int cnt;
ll ans;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &tp, &d);
		ans += d;
		if(d > 0){
			if(tp == 0){
				if(st[1].size() < cnt){
					st[1].insert(d);
					ans += d;
				}else if(!st[1].empty() && d > *st[1].begin()){
					int i = *st[1].begin();
					st[1].erase(st[1].begin());
					ans -= i;
					st[0].insert(i);
					ans += d;
					st[1].insert(d);
				}else{
					st[0].insert(d);
				}
			}else{
				cnt++;
				st[2].insert(d);
				if(cnt == 1){
					x = d;
				}else{
					if(d < x) swap(x, d);
					st[0].insert(d);
				}
				//printf("%d %d--\n", cnt, st[1].size());
				if(!st[0].empty() && st[1].size() < cnt){
					int i = *st[0].rbegin();
					st[0].erase(i);
					st[1].insert(i);
					ans += i;
				}
			}
		}else{
			d = -d;
			if(tp == 0){
				if(st[0].find(d) == st[0].end()){
					st[1].erase(d);
					ans -= d;
					if(!st[0].empty()){
						int i = *st[0].rbegin();
						st[0].erase(i);
						st[1].insert(i);
						ans += i;
					}
				}else{
					st[0].erase(d);
				}
			}else{
				cnt--;
				st[2].erase(d);
				if(x == d){
					if(cnt){
						int i = *st[2].begin();
						if(st[0].find(i) == st[0].end()){
							st[1].erase(i);
							ans -= i;
						}else{
							st[0].erase(i);
						} 
						x = i;
					}
					if(st[1].size() > cnt){
						int j = *st[1].begin();
						ans -= j;
						st[1].erase(j);
						st[0].insert(j);
					}
					
				}else if(st[0].find(d) == st[0].end()){
					st[1].erase(d);
					ans -= d;
				}else{
					st[0].erase(d);
					if(st[1].size() > cnt){
						int j = *st[1].begin();
						ans -= j;
						st[1].erase(j);
						st[0].insert(j);
					}
				}
			}
		}
		//printf("%d--\n", st[1].size());
		printf("%lld\n", ans);
	}
}