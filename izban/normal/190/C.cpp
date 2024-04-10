#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long
     
using namespace std;

#pragma comment(linker,"/STACK:64000000")

string str(int i) {
    stringstream ss;
    ss << i;
    string res="";
    ss >> res;
    return res;
}

const int maxn=1<<17, inf=1000000000;
const ll q=1000000007;
const double eps=1e-9;


int n,m;
string s,ans;
vector<int> v;
bool f;

void allbad() {
    cout << "Error occurred";
    exit(0);
}

int main() { 
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    cin >> n;
    while (cin >> s) {
        if (f && !v.size()) 
            allbad();
        if (v.size())
            v[v.size()-1]++;
        if (ans.size() && ans[ans.length()-1]!='<')
            ans+=",";
        if (s=="pair") {
            v.push_back(0);
            ans+=s+"<";
        }
        if (s=="int") {
            ans+="int";
            while (v.size() && v.back()==2) {
                ans+=">";
                v.pop_back();
            }
        }
        f=true;
    }
    if (v.size()) 
        allbad();
    int i=ans[0]==',';
    while (i<ans.size()) 
        cout << ans[i++];
    return 0;
}