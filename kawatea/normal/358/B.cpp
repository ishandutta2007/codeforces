#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, i, j;
    string s, t;
    
    cin >> n;
    
    s = "<3";
    
    for (i = 0; i < n; i++) {
        string tmp;
        
        cin >> tmp;
        
        s += tmp;
        s += "<3";
    }
    
    cin >> t;
    
    for (i = 0, j = 0; i < s.size(); i++) {
        int f = 0;
        
        while (j < t.size()) {
            if (s[i] == t[j]) {
                f = 1;
                
                break;
            }
            
            j++;
        }
        
        if (f == 1) {
            j++;
        } else {
            break;
        }
    }
    
    if (i == s.size()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}