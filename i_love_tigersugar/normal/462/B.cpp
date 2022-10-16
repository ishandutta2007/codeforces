#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#define se   second
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int main(void) {
    int n,k;
    string s;
    cin>>n>>k>>s;
    long long res=0;
    map<char,int> mp;
    FORE(it,s) mp[*it]++;
    vector<int> v;
    FORE(it,mp) v.push_back(it->se);
    sort(v.begin(),v.end(),greater<int>());
    FORE(it,v) {
        int t=min(*it,k);
        k-=t;
        res+=1LL*t*t;
    }
    cout<<res;
    return 0;
}