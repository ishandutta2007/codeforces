#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000

bool iscon(char a){
	return a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u';
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin>>s;

	string ans="";

	int num=0;
	bool allequal=1;
	bool fcom=1;

	for(int i=0;i<s.size();i++){
		if(!iscon(s[i])){
			ans+=s[i];
			num=0;
			allequal=1;
			fcom=1;
		}
		else{
			//cout<<i<<" "<<allequal<<endl;
			if(fcom){
				num++;
				fcom=false;
				ans+=s[i];
			}
			else{
				if(allequal){
					if(s[i]==s[i-1]){
						ans+=s[i];num++;
					}
					else if(s[i]!=s[i-1] && num>1){
						ans+=" ";
						ans+=s[i];
						num=1;
					}
					else{
						ans+=s[i];
						allequal=false;
						num++;
					}
				}
				else{
					if(num>1){
						ans+=" ";
						ans+=s[i];
						num=1;
						allequal=true;
					}
					else{
						ans+=s[i];
						num++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}