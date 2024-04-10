#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int l, r, q;
    l = r = q = 0;
    for(int i = 0; i < n; i++) {
        if(s.at(i) == '(') l++;
        if(s.at(i) == ')') r++;
        if(s.at(i) == '?') q++;
    }
    if(n%2) {
        std::cout << ":(\n";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(s.at(i) == '?') {
            if(l < n/2) {
                l++;
                s.at(i) = '(';
            }
            else {
                r++;
                s.at(i) = ')';
            }
        }
    }
    if(l != n/2) {
        std::cout << ":(\n";
        return 0;
    }
    int g = 0;
    for(int i = 0; i < n; i++) {
        if(s.at(i) == '(') g++;
        else g--;
        if(g <= 0 && i < n-1) {
            std::cout << ":(\n";
            return 0;
        }
        if(g != 0 && i == n-1) {
            std::cout << ":(\n";
            return 0;
        }
    }
    std::cout << s << '\n';
}