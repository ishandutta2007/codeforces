#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
const int mxN = 500;

int main() {
    int t; cin >> t;
    while(t--) {
        int a,b; cin >> a >> b;
        string s; cin >> s;
        s.push_back('0');
        int n = s.length(), ans =0;
        bool prev=false;

        vector<int> gaps;
        int tmp=0;
        bool one =false;
        for(int i=0;i<n;++i) {
            if(s[i]=='1') {
                if(!prev and one) {
                    gaps.push_back(tmp);
                    
                }
                one = true;
                
            } else {
                if(prev) {
                    tmp=1;
                } else {
                    tmp++;
                }
            } 
            prev = s[i]=='1';
        }
        ans = (gaps.size()+one)*a;
        for(int g: gaps) {
            if(g*b < a) {
                ans+=g*b-a;
            }
        }
        cout << ans << endl;

    }
    
}