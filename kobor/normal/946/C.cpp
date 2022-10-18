#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	char l='a';
	cin>>s;
	for(int i=0; i<s.length(); i++){
		if(l>'z'){
			break;
		}
		if(s[i]<=l){
			s[i]=l;
			l++;
		}
	}
	if(l>'z'){
		cout<<s<<'\n';
	}
	else{
		cout<<-1<<'\n';
	}
	return 0;
}