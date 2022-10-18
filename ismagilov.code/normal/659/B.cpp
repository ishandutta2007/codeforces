#include <bits/stdc++.h>
    
using namespace std;
int main() {
		int n, m, a, b;
		cin >> n >> m;
	    string s;
	    vector <pair<int, string> > gg[m+1];
    	
    	for(int i = 0; i < n; i++){
    		cin >> s >> a >> b;
    		gg[a].push_back(make_pair(b, s));
    	}
    	for(int i = 1; i <= m; i++){
    		sort(gg[i].begin(), gg[i].end());
    		reverse(gg[i].begin(), gg[i].end());
    		bool p = false;
    		if (gg[i].size()>2){
    			if (gg[i][1].first == gg[i][2].first){
    				cout << '?' << endl;
    				p = true;
    			}
    		}
    		if (!p){
    		    cout << gg[i][0].second << " " << gg[i][1].second << endl;
    		}
    	}
    	return 0;
}