#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	int unread = 0;
	vector<int> fq_time;
	vector<deque<int>> apps(n);
	set<pair<int, int>> order; // time, app #
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			fq_time.push_back(qi);
			int x;
			cin >> x, -- x;
			if(apps[x].empty()){
				order.insert({qi, x});
			}
			apps[x].push_back(qi);
			++ unread;
		}
		else if(type == 2){
			int x;
			cin >> x, -- x;
			unread -= (int)apps[x].size();
			if(!apps[x].empty()){
				order.erase({apps[x].front(), x});
			}
			apps[x].clear();
		}
		else{
			int t;
			cin >> t, t = fq_time[t - 1];
			while(!order.empty() && order.begin()->first <= t){
				-- unread;
				auto [qi, x] = *order.begin(); order.erase(order.begin());
				apps[x].pop_front();
				if(!apps[x].empty()){
					order.insert({apps[x].front(), x});
				}
			}
		}
		cout << unread << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////