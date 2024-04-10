#include <bits/stdc++.h>
using namespace std; 
//int lcf(long long a,long long b){
//	if(a<b)swap(a,b);
//	if(a%b==0)return b;
//	return lcf(b,a-b);
//}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long a,b;
	cin>>a>>b;
	if(a==b||a%b==0||b%a==0){
		cout<<"0"<<endl;
		return 0;
	}
	long long diff=abs(a-b);
	queue<long long>q;
	stack<long long>s;
	priority_queue<long long>pq;
	for(long long i=1;i<=sqrt(diff);i++){
		if(diff%i==0){
			if(i!=1)q.push(i);
			s.push(diff/i);
		}
	}
	long long min=a*b,index=0;
	while(!q.empty()){
		long long t=(q.front()-a%q.front())%q.front();
		q.pop();
		pq.push(t);
	}
	while(!s.empty()){
		long long t=(s.top()-a%s.top())%s.top();
		s.pop();
		pq.push(t);
	}
	while(!pq.empty()){
		long long t=pq.top();
		pq.pop();
		long long tt=(a+t)*(b+t)/__gcd((a+t),(b+t));
//		cout<<t<<' '<<tt<<endl;
		if(tt<=min){
			min=tt;
			index=t;
		}
	}
	cout<<index<<endl;
	//cout<<(index-a%index)%index<<endl;
	return 0;
}