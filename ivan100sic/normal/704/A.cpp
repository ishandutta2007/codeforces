#include "bits/stdc++.h"
using namespace std;

struct Notif {
	bool read;
	int app, time, order;	
};

int N, Q, vreme, unread;
list<Notif*> hrono, apps[300005];

int main(){
	scanf("%d%d", &N, &Q);
	
	while (Q--){
		int t, x;
		scanf("%d%d", &t, &x);
		if (t == 1){
			auto nov = new Notif;
			nov->read = false;
			nov->app = x;
			nov->time = ++vreme;
			hrono.push_back(nov);
			apps[x].push_back(nov);
			unread++;
		} else if (t == 3){
			while (hrono.size()){
				auto& notif = **hrono.begin();
				if (notif.time <= x){
					if (!notif.read){
						notif.read = true;
						unread--;
					}
					hrono.pop_front();
				} else break;
			}
		} else {
			while (apps[x].size()){
				auto& notif = **apps[x].begin();
				if (!notif.read){
					notif.read = true;
					unread--;
				}
				apps[x].pop_front();
			}
		}
		printf("%d\n", unread);
	}
	return 0;
}