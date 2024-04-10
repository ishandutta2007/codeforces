#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sb{
	int a,b;
	bool operator <(const sb& x)const{
		if(a==x.a){return b>x.b;}
		return a<x.a;
	}
}tmp,tmp2;

int n,m,t,id,used[500500],k;
priority_queue<sb> q;
queue<int> q1;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		if(k==1){
			id++;
			tmp.b=id;
			scanf("%d",&tmp.a);
			q.push(tmp);
			q1.push(id);
		}
		if(k==2){
			while(used[q1.front()]){q1.pop();}
			printf("%d ",q1.front());used[q1.front()]=1;q1.pop();
		}
		if(k==3){
			while(used[q.top().b]){q.pop();}
			printf("%d ",q.top().b);used[q.top().b]=1;q.pop();
		}
	}
}