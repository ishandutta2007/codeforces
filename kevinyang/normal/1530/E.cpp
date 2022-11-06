#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string ss;
		cin >> ss;
		int n = ss.length();
		if(true){
			set<char>st;
			for(int i = 0; i<n; i++){
				st.insert(ss[i]);
			}
			if(st.size()==1){
				cout << ss << "\n";
				continue;
			}
		}
		if(true){
			map<char,int>freq;
			bool overone = false;
			for(int i = 0; i<n; i++){
				freq[ss[i]]++;
				if(freq[ss[i]]>1)overone = true;
			}
			if(!overone){
				sort(ss.begin(),ss.end());
				cout << ss << "\n";
				continue;
			}
		}
		map<char,char>hm;
		map<char,char>rev;
		string s = "";
		set<char>chars;
		for(int i = 0; i<n; i++){
			chars.insert(ss[i]);
		}
		for(int i = 0; i<26; i++){
			if(chars.size()==0)break;
			char ch = *chars.begin();
			chars.erase(ch);
			hm['a'+i] = ch;
			rev[ch] = 'a'+i;
		}
		for(char nxt: ss){
			s.push_back(rev[nxt]);
		}
		map<char,int>freq;
		for(int i = 0; i<n; i++){
			freq[s[i]]++;
		}
		if(true){
			bool f = false;
			for(int i = 0; i<26; i++){
				if(freq['a'+i]==1)f = true;
			}
			if(f){
				string ans = "";
				for(int i = 0; i<26; i++){
					if(freq['a'+i]==1){
						freq['a'+i]=0;
						ans+=(char)('a'+i);
						break;
					}
				}
				for(int j = 0; j<26; j++){
					for(int i = 0; i<freq['a'+j]; i++){
						ans+=(char)('a'+j);
					}
				}
				for(int i = 0; i<n; i++){
					cout << hm[ans[i]];
				}
				cout << "\n";
				continue;
			}
		}
		if(freq['a']>1){
			string ans = "aa";
			freq['a']-=2;
			bool prev = true;
			bool f = true;
			for(int i = 2; i<n; i++){
				if(prev){
					bool found = false;
					for(int j = 1; j<26; j++){
						if(freq['a'+j]>0){
							freq['a'+j]--;
							ans.push_back((char)('a'+j));
							found = true;
							break;
						}
					}
					if(!found)f = false;
					prev = false;
					if(!f)break;
				}
				else{
					if(freq['a']>0){
						freq['a']--;
						ans.push_back('a');
						prev = true;
					}
					else{
						for(int j = 1; j<26; j++){
							if(freq['a'+j]>0){
								freq['a'+j]--;
								ans.push_back((char)('a'+j));
								break;
							}
						}
					}
				}
			}
			if(f){
				assert(ans.size()==n);
				for(int i = 0; i<n; i++){
					cout << hm[ans[i]];
				}
				cout << "\n";
				continue;
			}
		}
		freq.clear();
		for(int i = 0; i<n; i++){
			freq[s[i]]++;
		}
		//cerr << "nae\n";
		if(true){
			string ans = "ab";
			freq['a']--;
			freq['b']--;
			if(freq['c']>0){
				for(int i = 0; i<freq['a']; i++){
					ans.push_back('a');
				}
				ans.push_back('c');
				freq['c']--;
				for(int j = 1; j<26; j++){
					for(int i = 0; i<freq['a'+j]; i++){
						ans.push_back((char)('a'+j));
					}
				}
			}
			else{
				//cerr << "nae2\n";
				for(int i = 0; i<freq['b']; i++){
					ans.push_back('b');
				}
				for(int i = 0; i<freq['a']; i++){
					ans.push_back('a');
				}
			}
			assert(ans.size()==n);
			//cerr << ans.size() << "\n";
			for(int i = 0; i<n; i++){
				cout << hm[ans[i]];
			}
			cout << "\n";
		}
		//cerr << "nae\n";
	}
	return 0;
}