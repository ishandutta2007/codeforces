#include <bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;

#define MAXN 1000000007
#define INF INT_MAX

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int mark;
	cin>>mark;

	int vol=0, maxvol=0;

	while(mark>0){
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]>='A' && s[i]<='Z'){
				vol++;
			}
		}
		if(vol>maxvol)maxvol=vol;
		vol=0;
		mark-=s.size();
		mark--;
	}

	cout<<maxvol<<endl;

	return 0;
}