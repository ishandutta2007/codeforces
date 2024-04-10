#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

map<int,int> st,ss;
map<int,int> :: iterator it;
pair<int,int> a[345678];
int n,b[345678],ans;
char ch;
long long x;


int main() {
    cin>>n>>x;
    for (int i=1; i<=n; i++){
        if (x%i==0 && x/i<=n) ans++;
    
    }  
    cout<<ans;
    return 0;
}