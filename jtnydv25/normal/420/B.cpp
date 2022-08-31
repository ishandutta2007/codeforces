#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 19;

pair<char, int> events[N];
int in[N], out[N], invalid[N];
vector<pair<char, int> > vec;
vector<int> vec2;
set<int> st;
int main(){
	int n, m;
	cin.tie(0);
	cin >> n >> m;
	int currplus = 0, currminus = 0;
	bool invalidateplus = 0, invalidateminus = 0;
	for(int i = 1; i <= m; i++){
		cin >> events[i].first >> events[i].second;	
		if(events[i].first == '+'){
			in[events[i].second] = i;
			currplus ++;
		}
		else{
			if(!in[events[i].second]){
				vec.push_back({'+', events[i].second});
			}
			out[events[i].second] = i;
			currminus--;
		}
	}
	reverse(vec.begin(), vec.end());
	for(int i = 1; i <= m; i++) vec.push_back(events[i]);
	for(int i = 1; i <= n; i++) if(!in[i] && !out[i]) vec2.push_back(i);
	bool flag = 1;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].first == '+'){
			st.insert(vec[i].second);
		}
		else st.erase(vec[i].second);
		if(!st.empty() && !st.count(vec[0].second))
			flag = 0;
	}

	if(flag) vec2.push_back(vec[0].second);
	sort(vec2.begin(), vec2.end());
	cout << vec2.size() << endl;
	for(int x : vec2) cout << x << " ";
}