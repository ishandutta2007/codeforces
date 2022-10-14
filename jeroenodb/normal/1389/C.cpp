#include <iostream>
#include <string>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)

int main() {
    int t;
    cin >> t;
    while(t--) {
    	string s;
    	cin >> s;
    	int n = s.length();
		int best = n;
		for(char a='0';a<='9';++a) {
			for(char b=a;b<='9';++b) {
				int cur = 0;
				char last=' ';
				for(int i=0;i<n;++i) {
					//cout << i << ' ';
					if(s[i]!=a and s[i]!=b) {
						//cout << "delete noncorfming\n";
						++cur; continue;
					} 
					if(s[i]==last and a!=b) {
						//cout << "not right order\n";
						++cur;
					} else {
						//cout << "the same but doesnt matter\n";
						last = s[i];
					}
				}
				if((n-cur)%2==1 and a!=b) cur++;
				best = min(cur,best);
			}
		}
		cout << best << endl;
    }
}