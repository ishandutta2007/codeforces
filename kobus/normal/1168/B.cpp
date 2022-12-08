#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAXN 1123
#define INF (int)1.5e12
#define INFF LLONG_MAX/2
#define eps 1e-4


set<string> ruim;

void genruim(){
	for(int n=3;n<=10;n++){
			for(int i=0;i<(1<<n);i++){
			string s;
			for(int j=0;j<n;j++){
				if((i>>j)%2)s.pb('0');
				else s.pb('1');
			}
			bool bad=0;
			for(int x=0;x<n;x++){
				for(int k=1;k<n;k++){
					if(x+2*k>=n)break;
					if(s[x]==s[x+k] && s[x+k]==s[x+2*k])bad=1;
				}
			}
			if(bad)ruim.insert(s);
			//if(bad)cout<<s<<endl;
		}

	}
}


int32_t main(){
	cout<<setprecision(5)<<fixed;

	int n;
	string s;
	cin>>s;
	n=s.size();
	int resp=0;
	genruim();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string ss;
			for(int k=i;k<=j;k++)ss.pb(s[k]);
			if(ruim.find(ss)!=ruim.end()){
				//cout<<ss<<" "<<i<<" "<<n-j<<endl;
				resp+=n-j;
				break;
			}
		}
	}
	cout<<resp<<endl;

    return 0;
}