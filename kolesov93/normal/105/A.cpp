#include <stdio.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <memory.h>
#include <queue>
#include <string>
#include <string.h>
#include <cmath>
#include <utility>
#include <time.h>

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))
#define OUT_RT cerr << (float(clock()) / CLOCKS_PER_SEC) << endl

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

vector<pair<string,int> > e;
string s;
int x;

int main(){
//      freopen("input.txt","r",stdin);
//      freopen("output.txt","w",stdout);

        int n, m;
        double k;
        cin >> n >> m >> k;     
        for(int i=0;i<n;i++){
                cin >> s >> x;
                int newexp = (int)( floor(double(x) * k + 0.00001) );
                if(  newexp >= 100 )
                        e.push_back(make_pair(s, newexp));
        }
        for(int i=0;i<m;i++){
                cin >> s;

                bool f = false;
                for(int j=0;j<(int)e.size();j++) if(e[j].first == s){
                        f = true;
                        break;
                }
                if(!f)
                        e.push_back(make_pair(s, 0));
        }
        sort(e.begin(), e.end());

        cout << e.size() << endl;
        for(int i=0;i<(int)e.size();i++)
                cout << e[i].first << " " << e[i].second << endl;
        return 0;
}