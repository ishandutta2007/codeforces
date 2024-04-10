#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    int n = s.size();
    int i = 0;
    while (i < n && s[i] == 'a') {
        i ++;
    }
    if (i == n) {
        // aaa..a
        s[n - 1] = 'z';
    } else {
        int j = i;
        while (j < n && s[j] != 'a') {
            s[j] --;
            j ++;
        }
    }
    std::cout << s << std::endl;
}