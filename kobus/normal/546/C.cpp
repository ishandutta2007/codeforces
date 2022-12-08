#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX;
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	deque<int> s1;
	deque<int> s2;

	int n1;
	cin>>n1;
	for(int i=0;i<n1;i++){
		int y;cin>>y;
		s1.push_back(y);
	}
	int n2;
	cin>>n2;
	for(int i=0;i<n2;i++){
		int y;cin>>y;
		s2.push_back(y);
	}


	int op=0;
	while(op!=1123456){
		if(s1.size()==0){
			cout<<op<<" "<<2<<endl;
			return 0;
		}
		if(s2.size()==0){
			cout<<op<<" "<<1<<endl;
			return 0;
		}
		int a1=s1.front();
		s1.pop_front();
		int a2=s2.front();
		s2.pop_front();
		//cout<<op<<": "<<a1<<" "<<a2<<endl;
		if(a1>a2){
			s1.push_back(a2);
			s1.push_back(a1);
		}
		else{
			s2.push_back(a1);
			s2.push_back(a2);
		}
		op++;
	}
	cout<<-1<<endl;

	return 0;
}