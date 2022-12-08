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
#define INF INT_MAX/2
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool lower=0;

	int low=0;
	int upp=0;

	string s;
	cin>>s;

	for(int i=0;i<s.size();i++){
		if(s[i]>='a' && s[i]<='z'){
			low++;
		}
		else upp++;
	}

	if(low>=upp)lower=1;

	for(int i=0;i<s.size();i++){
		if(s[i]>='a' && s[i]<='z'){
			if(!lower){
				s[i]=s[i]-'a'+'A';
			}
		}
		else{
			if(lower){
				s[i]=s[i]-'A'+'a';
			}
		}
	}

	cout<<s<<endl;

	return 0;
}