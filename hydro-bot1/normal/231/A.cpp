// Hydro submission #62ae724a02aab04f3f7cfcea@1655599690201
#include<iostream>
using namespace std;
int main() {
	int n,cnt=0,cntcnt=0;
	bool a,b,c;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a >> b >> c;
		if(a==true) {
			cnt++;
		}
		if(b==true) {
			cnt++;
		}
		if(c==true) {
			cnt++;
		}
		if(cnt>=2) {
			cntcnt++;
		}
		cnt=0;
	}
	cout << cntcnt;
	return 0;
}