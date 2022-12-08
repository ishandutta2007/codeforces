#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int h=10*(s[0]-'0')+(s[1]-'0');
	int m=10*(s[3]-'0')+(s[4]-'0');

	int mark=0;
	while(true){
		if(m%10==((h-h%10)/10) && h%10==((m-m%10)/10)){
			cout<<mark<<"\n";
			return 0;
		}
		mark++;
		m++;
		if(m==60){
			m=0;
			h++;
		}
		if(h==24){
			h=0;
		}
	}

	return 0;
}