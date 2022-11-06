#include<iostream>
#include<string>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    string::iterator i = s.begin();
    string::iterator j = t.begin();
    long start = 0;
    while ((i != s.end()) && (j != t.end())) {
        if (*i == *j)
            ++i;
        ++j;
        ++start;
    };
    if (i == s.end()) {
        long end = t.length() - 1;
        i = s.end() - 1;
        j = t.end() - 1;
        while ((i != s.begin() - 1) && (j != t.begin() - 1)) {
            if (*i == *j)
                --i;
            --j;
            --end;
        };
        cout << max(0L, end - start + 2);
        //cout << start << ' ' << end;
    } else {
        cout << 0;
    };
    return 0;
}