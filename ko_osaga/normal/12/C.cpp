#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int a[105];
map<string,int> mp;
vector<int> v;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        mp[s]++;
    }
    for(auto &i : mp){
        v.push_back(i.second);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int ret = 0, p = 0;
    for(auto &i : v){
        ret += i * a[p++];
    }
cout << ret;
    p = 0;
    ret = 0;
    reverse(a,a+n);
    for(auto &i : v){
        ret += i * a[p++];
    }
cout << ' ' << ret;
}