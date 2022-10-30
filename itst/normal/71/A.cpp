#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
    	string s;
    	cin >> s;
    	if(s.size() <= 10)
    		cout << s << endl;
    	else
    		cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
	}
	return 0;
}