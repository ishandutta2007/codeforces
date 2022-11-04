#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n,k;
string s;

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>k>>s;
		int cnt[256]={};
		for(int i=0;i<n;++i)++cnt[s[i]];
		bool done=false;
		for(int i=n;i>=0&&!done;--i){
			int need=0;
			char mc='a';
			for(char j='a';j<='z';++j)if(cnt[j]%k){
				need+=k-cnt[j]%k;
//				cerr<<s[i]<<" "<<j<<endl;
				if(i<n&&mc<=s[i])mc=j;
			}
//			cerr<<i<<" "<<need<<" "<<(n-(i+need))<<" "<<mc<<endl;
			if(need+i<=n&&(n-(i+need))%k==0&&(i==n||mc>s[i]||(n-(i+need)&&s[i]!='z'))){
				done=true;
				if(i==n)break;
				if(n-(i+need)){++s[i++];++cnt[s[i-1]];}
				else {s[i++]=mc;++cnt[mc];}
				need=0;
				for(char j='a';j<='z';++j)if(cnt[j]%k)need+=k-cnt[j]%k;
				int choose=n-(i+need);
				assert(choose%k==0);
				while(choose--)s[i++]='a';
				char cp='a';
				while(need){
					while(cnt[cp]%k==0)++cp;
					s[i++]=cp;
					--need;++cnt[cp];
				}
			}
			if(i)--cnt[s[i-1]];
		}
		if(!done)cout<<"-1\n";
		else cout<<s<<'\n';
	}
}