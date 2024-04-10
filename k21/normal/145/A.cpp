    #include <algorithm>
    #include <cctype>
    #include <cmath>
    #include <cstdio>
    #include <cstring>
    #include <deque>
    #include <iostream>
    #include <list>
    #include <map>
    #include <queue>
    #include <set>
    #include <sstream>
    #include <stack>
    #include <string>
    #include <vector>

    using namespace std;

    #define DEBUG(x) cout << '>' << #x << " = " << (x) << endl;
    #define FOR(i,a,b) for(int i=(a);i<=(b);++i)
    #define FORD(i,a,b) for(int i=(a);i>=(b);--i)
    #define REP(i,a) for(int i=0;i<(a);++i)

    typedef long long ll;

    char a[100100];
    char b[100100];

    int main() {
            gets(a); gets(b);
            int l = strlen(a);
            int a4 = 0, b4 = 0;
            REP(i,l) {
                    if (a[i]=='4') ++a4;
                    if (b[i]=='4') ++b4;
            }
            int sum = 2*abs(a4-b4);
            int i = 0;
            while (a4 > b4) {
                    if (a[i] == '4' && b[i] == '7') {a[i] = '7';
                    --a4;}
                    ++i;
            }
            while (a4 < b4) {
                    if (a[i] == '7' && b[i] == '4') {a[i] = '4';
                    ++a4;}
                    ++i;
            }
            REP(j,l) if (a[j] != b[j]) ++sum;
            printf("%d\n", sum/2);
            return 0;
    }