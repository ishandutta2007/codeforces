#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 200005;

int n;
lint a[MAXN];
int main(){
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	vector<lint> ret;
	for(int j=59; j>=0; j--){
		vector<lint> fuck;
		vector<int> pos;
		for(int k=1; k<=n; k++){
			if((a[k] >> j) == 1){
				fuck.push_back(a[k]);
				pos.push_back(0);
			}
		}
		int ptr = 0;
		for(int i = 0; i<fuck.size(); i++){
			if(ptr > ret.size()){
				puts("No");
				return 0;
			}
			pos[i] = ptr;
			int incr = 0;
			while(ptr < ret.size() && (ret[ptr] >> j) % 2 == 0){
				ptr++;
				incr++;
			}
			ptr++;
		}
		ptr = 0;
		vector<lint> nret;
		for(int i=0; i<pos.size(); i++){
			while(ptr < pos[i]){
				nret.push_back(ret[ptr++]);
			}
			nret.push_back(fuck[i]);
		}
		while(ptr < ret.size()){
			nret.push_back(ret[ptr++]);
		}
		ret = nret;
	}
	vector<lint> psum;
	lint cur = 0;
	for(int i=0; i<ret.size(); i++){
		cur ^= ret[i];
		psum.push_back(cur);
	}
	puts("Yes");
	for(int i=0; i<ret.size(); i++) printf("%lld ", ret[i]);
	for(int i=1; i<psum.size(); i++){
		if(psum[i-1] >= psum[i]){
			puts("No");
			return 0;
		}
	}
}