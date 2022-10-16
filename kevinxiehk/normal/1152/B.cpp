#include <bits/stdc++.h>
using namespace std; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a;
	cin>>a;
	int t=1;
	while(a>=t){
		t=t<<1;
	//	cout<<t<<" ";	
	}
	t=t>>1;
	int cnt=0;
	queue <int> q;
	bool b=false;
	while(1){
		for(int i=0;i<=20;i++){
			//cout<<pow(2,i);
			if(a==(pow(2,i)-1)){
				b=true;
				break;
			}
		}
		if(b)break; 
		if(cnt%2==0){
			while(t&a)t=t>>1;
			t=t<<1;
			q.push(t);
			a=a^((t)-1);
		}
		else a++;
	//	cout<<a<<endl;
		cnt++;
	}
	cout<<cnt<<endl;
	while(!q.empty()){
		t=q.front();
		int j=0;
		while(pow(2,j)!=t)j++;
		cout<<j;
		q.pop();
		if(q.empty())cout<<endl;
		else cout<<" ";
	}
	cout<<endl;
	return 0;
}