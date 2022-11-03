#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	cin >> s;
	string t = s;
	string s1 = "bdpqAHIMOoTUVvWwXxY";
	string s2 = "dbqpAHIMOoTUVvWwXxY";
	int o;
	for(int i=0;i<t.length();i++){
		o = s1.find(t[i],0);
		if(o==string::npos){
			cout << "NIE";
			return 0;
		}else{
			t[i] = s2[o];
		}
	}
	reverse(t.begin(),t.end());
	if(s==t){
		cout << "TAK";
	}else{
		cout << "NIE";
	}
}