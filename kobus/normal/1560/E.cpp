#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 312345;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define MOD 1000000007

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector<char> let;
		set<char> found;
		for(int i=s.size()-1;i>=0;i--){
			if(found.find(s[i])==found.end()){
				found.insert(s[i]);
				let.pb(s[i]);
			}
		}
		reverse(let.begin(),let.end());
		vector<int> freq(26);
		for(int i=0;i<s.size();i++){
			freq[s[i]-'a']++;
		}
		bool ruim=0;
		for(int i=0;i<let.size();i++){
			//cout<<(int)(let[i]-'a')<<" "<<let.size()-i<<"\n";
			if((freq[let[i]-'a']%(i+1))!=0)ruim=1;
			freq[let[i]-'a']/=(i+1);
		}
		if(ruim){
			cout<<-1<<"\n";
			continue;
		}
		for(int i=0;i<26;i++){
			//cout<<char(i+'a')<<" "<<freq[i]<<endl;
		}
		int ne=let.size();
		string f;
		for(int i=0;i<s.size();i++){
			f.pb(s[i]);
			freq[s[i]-'a']--;
			if(freq[s[i]-'a']==0)ne--;
			if(ne==0)break;
		}
		set<int> st;
		for(int i=0;i<f.size();i++)st.insert(i);
		map<char,vector<int>> mp;
		for(int i=0;i<f.size();i++)mp[s[i]].pb(i);
		string curr=f;
		int it=0;
		int leter=0;
		while(curr.size()>0){
			//cout<<curr<<endl;
			for(int i=it;i<it+curr.size();i++){
				if(i>s.size()||s[i]!=curr[i-it])ruim=1;
			}
			it+=curr.size();
			if(ruim)break;
			for(auto x:mp[let[leter]]){
				st.erase(x);
			}
			leter++;
			curr.clear();
			for(auto x:st)curr.pb(f[x]);
		}

		if(ruim){
			cout<<-1<<"\n";
			continue;
		}

		cout<<f<<" ";
		for(char c:let)cout<<c;
		cout<<"\n";

	}
	
}