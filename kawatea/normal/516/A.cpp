#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char s[16];

int main()
{
    int n, i;
    vector <int> v;
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] <= '1') continue;
        
        if (s[i] == '4') {
            v.push_back(3);
            v.push_back(2);
            v.push_back(2);
        } else if (s[i] == '6') {
            v.push_back(5);
            v.push_back(3);
        } else if (s[i] == '8') {
            v.push_back(7);
            v.push_back(2);
            v.push_back(2);
            v.push_back(2);
        } else if (s[i] == '9') {
            v.push_back(7);
            v.push_back(3);
            v.push_back(3);
            v.push_back(2);
        } else {
            v.push_back(s[i] - '0');
        }
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) printf("%d", v[i]);
    
    puts("");
    
    return 0;
}