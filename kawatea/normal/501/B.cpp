#include <cstdio>
#include <vector>
#include <string>

using namespace std;

char s1[21];
char s2[21];

int main()
{
    int n, i, j;
    vector <pair<string, string> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        string s, t;
        
        scanf("%s %s", s1, s2);
        
        s = (string)s1;
        t = (string)s2;
        
        for (j = 0; j < v.size(); j++) {
            if (v[j].second == s) {
                v[j].second = t;
                
                break;
            }
        }
        
        if (j == v.size()) v.push_back(make_pair(s, t));
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%s %s\n", v[i].first.c_str(), v[i].second.c_str());
    
    return 0;
}