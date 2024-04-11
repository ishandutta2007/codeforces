#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

string s;
int n, a, b, k;

int main(){
	cin >> n >> a >> b >> k;
	cin >> s;
	vector<int> v;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '0'){
			int e = i;
			while(e < s.size() && s[e] == '0') e++;
			for(int j=i+b-1; j<e; j+=b){
				v.push_back(j+1);
			}
			i = e;
			continue;
		}
	}
	printf("%d\n", v.size() + 1 - a);
	for(int i=a-1; i<v.size(); i++){
		printf("%d ", v[i]);
	}
}