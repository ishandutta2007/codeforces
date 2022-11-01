#include<bits/stdc++.h>
using namespace std;
vector < int > Child[2001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	queue < int > q;
	int cou = 0 , N;
	cin >> N;
	for(int i = 1 ; i <= N ; i++){
		int a;
		cin >> a;
		if(a == -1)	q.push(i);
		else	Child[a].push_back(i);
	}
	while(!q.empty()){
		queue < int > q1;
		cou++;
		while(!q.empty()){
			int t = q.front();
			q.pop();
			for(int i = 0 ; i < Child[t].size() ; i++)
				q1.push(Child[t][i]);
		}
		while(!q1.empty()){
			q.push(q1.front());
			q1.pop();
		}
	}
	cout << cou;
	return 0;
}