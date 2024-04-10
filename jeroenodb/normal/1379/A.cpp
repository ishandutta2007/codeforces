#include <iostream>
#include <string>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)

string s;
int n;
const char aba[] = "abacaba";
bool doubleab(string& str) {
	bool forced=false;
	for(int i=0;i<n;++i) {
		bool match = true;
		for(int j=0;j<7;++j) {
			if(str[i+j]!=aba[j]) {
				match = false; break;
			}
		}
		if(match) {
			if(forced) {
				return true;
			} else forced = true;
		}
	}
	return false;
}
bool trysol(int i) {
	string d = s;
	for(int j=0;j<7;++j) {
		d[i+j] = aba[j];
	}
	if(!doubleab(d)) {
		for(int j=0;j<n;++j) {
			if(d[j]=='?') d[j] = 'z';
		}
		cout << "YES" << endl;
		cout << d << endl;
		return true;
	}
	return false;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
    	cin >> n;
    	cin >> s;
    	if(doubleab(s)) {
    		cout << "NO" << endl; continue;
    	}
    	bool done = false;
    	for(int i=0;i<n;++i) {
    		bool match = true;
    		for(int j=0;j<7;++j) {
    			if(s[i+j]!='?' and aba[j]!=s[i+j] ) {
    				match = false; break;
    			}
    		}
    		if(match) {
    			if(trysol(i)) {
    				done = true;
    				break;
    			}
    		}
    	}
    	if(done) continue;
    	cout << "NO" << endl;
    }
}