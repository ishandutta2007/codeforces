#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue <int>qq;
priority_queue <int,vector<int>,greater<int> > q;
queue<char> s;
queue<int> s2;
int i,j,k,n,mn,rn,l,res[100500];
char sb;
int main(){
	cin>>n;
	for(i=1;i<=n*2;i++){
		cin>>sb;
		if(sb=='+'){
			rn++;
			qq.push(rn);
		}
		if(sb=='-'){
			cin>>k;
			if(qq.empty()){puts("NO");return 0;}
			res[qq.top()]=k;qq.pop();
			s2.push(k);
		}
		s.push(sb);
	}
	for(i=1;i<=n*2;i++){
		if(s.front()=='+'){j++;q.push(res[j]);}
		if(s.front()=='-'){
			//printf("%d %d\n",q.top(),s2.front());
			if(q.top()!=s2.front()){puts("NO");return 0;}
			s2.pop();q.pop();
		}
		s.pop();
	}
	puts("YES");
	for(i=1;i<=n;i++){
		printf("%d ",res[i]);
	}
}