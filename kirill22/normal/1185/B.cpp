#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
   int n;
   cin >> n;
   while(n--) {
	   	string a, b;
	   	cin >> a >> b;
	   	vector<pair<char,int>> a1;
	   	char tmp = '7';
	   	int kol = 0;
	   	for(int i = 0;i < a.size();i++){
	   		if(a[i]==tmp){
	   			kol++;
	   		}
	   		else{
	   			a1.push_back({tmp, kol});
	   			kol = 1;
	   			tmp = a[i];
	   		}
	   		
	   	}
	   	if(kol != 0) {
	   		a1.push_back({tmp, kol});
	   	}
	   	
	   	vector<pair<char,int>> b1;
	   	tmp = '7';
	   	kol = 0;
	   	for(int i = 0;i < b.size();i++){
	   		if(b[i]==tmp){
	   			kol++;
	   		}
	   		else{
	   			b1.push_back({tmp, kol});
	   			kol = 1;
	   			tmp = b[i];
	   		}
	   		
	   	}
	   	if(kol != 0) {
	   		b1.push_back({tmp, kol});
	   	}
	   	if(a1.size() != b1.size()){
	   		cout <<"NO" << endl;
	   		continue;
	   	}
	   	bool f = true;
	   	for(int i =0;i < a1.size();i++){
	   		if(a1[i].first != b1[i].first || a1[i].second > b1[i].second) {
	   			cout <<"NO" << endl;
	   			f = false;
	   			break;
	   		}
	   	}
	   	if(f){
	   		cout << "YES" << endl;
	   	}
	   	
   }
}