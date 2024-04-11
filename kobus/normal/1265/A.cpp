#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAXN 1123
#define INF LLONG_MAX
#define MOD 32416187567


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			set<char> poss;
			poss.insert('a');
			poss.insert('b');
			poss.insert('c');
			if(s[i]=='?'){
				if(i>0)poss.erase(s[i-1]);
				if(i<s.size()-1 && s[i+1]!='?' && poss.find(s[i+1])!=poss.end())
					poss.erase(s[i+1]);
				s[i]=*poss.begin();
			}
		}
		//cout<<s<<endl;
		int ruim=0;
		for(int i=1;i<s.size();i++){
			if(s[i]==s[i-1]){
				cout<<-1<<endl;
				ruim=1;
				break;
			}
		}
		if(!ruim)cout<<s<<endl;
	}

	return 0;
}