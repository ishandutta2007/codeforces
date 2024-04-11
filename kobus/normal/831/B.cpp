#include	<bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;

#define MAXN 1000000007
#define INF 1123456789

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string l1,l2,tx;
	cin>>l1>>l2>>tx;

	for(int i=0;i<tx.length();i++){
		if(!((tx[i]>='A' && tx[i]<='Z')||(tx[i]>='a' && tx[i]<='z'))){
			continue;
		}
		bool upper=false;
		if(tx[i]>='A' && tx[i]<='Z'){
			upper=true;
			tx[i]=tx[i]-'A'+'a';
		}
		for(int j=0;j<26;j++){
			if(tx[i]==l1[j]){
				tx[i]=l2[j];
				break;
			}
		}
		if(upper==true){
			tx[i]=tx[i]-'a'+'A';
		}
	}
	cout<<tx<<"\n";

	return 0;
}