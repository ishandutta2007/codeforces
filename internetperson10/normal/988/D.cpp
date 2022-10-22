#include <bits/stdc++.h>

using namespace std;

set<long long int> points;

int main() {
    bool haveifoundtwough = false;
    int n, twofound, twofoundn;
    cin >> n;
    for(int a=0; a<n; a++) {
        long long int p;
        cin >> p;
        points.insert(p);
    }
    bool bestfound = false, latest = false;
    for(set<long long int>::iterator it=points.begin(); it!=points.end() && !bestfound; it++) {
        for(long long int a=0; a<32 && !bestfound; a++) {
            if(points.count(*it + (1 << a))) {
                haveifoundtwough = true;
                twofound = *it;
                twofoundn = (1 << a);
                if(latest) {
                    bestfound = true;
                    cout << "3\n";
                    cout << *it << ' ' << *it + (1 << (a-1)) << ' ' << *it + (1 << a);
                    break;
                }
                latest = true;
            }
            else latest = false;
        }
    }
    if(!bestfound) {
        if(haveifoundtwough) {
            cout << 2 << '\n' << twofound << ' ' << twofound+twofoundn;
        }
        else {
            cout << 1 << '\n' << *(points.begin());
        }
    }
}