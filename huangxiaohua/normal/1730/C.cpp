#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,lst;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	
	while(t--){
		cin>>s;
		n=s.size();s="$"+s;
		lst=0;
		
		priority_queue<char,vector<char>,greater<char> >q;
		
		for(char i='0';i<='9';i++){
			while(!q.empty()&&q.top()<=i){
				cout<<q.top();q.pop();
			}
			for(j=lst+1;j<=n;j++){
				if(s[j]==i){
					cout<<i;s[j]='z';
					for(k=lst+1;k<=j;k++){
						if(s[k]!='z')q.push(min(char(s[k]+1),'9'));
					}
					lst=j;
				}
			}
		}
		while(!q.empty()){
			cout<<q.top();q.pop();
		}
		cout<<'\n';
	}
}