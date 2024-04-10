#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, s;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &s, &n);
		priority_queue<int, vector<int>, greater<int> > q;
		vector<int> v;
		int val = 1;
		while(s){
			for(int i = 1;i <= s % 10;i++) q.push(val);
			s /= 10, val *= 10; 
		}
		while(q.size() + v.size() < n){
			int x = q.top();q.pop();
			if(x == 1) v.push_back(x);
			else for(int i = 1;i <= 10;i++) q.push(x / 10);
		}
		while(!q.empty()){
			int x = q.top();q.pop();
			if(v.size() == n) v.back() += x;
			else v.push_back(x);
		}
		for(int i = 0;i < v.size();i++) printf("%d ", v[i]);
		puts("");
	}
	
}