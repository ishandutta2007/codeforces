#include<iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define REP(i,a) for (int i = 0; i < (a); i++)

int main() {
    int n,k;
    cin>>n>>k;
    vector<int>a,b;
    REP(i,n) {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    REP(i,n) {
        int temp;
        cin>>temp;
        b.push_back(temp);
    }
    vector<int>p;
    map<int,int>mp;
    int done=0;
    REP(i,n) {
        if (mp[a[i]]==0) {
            mp[a[i]]=b[i];
            done++;
        } else if (mp[a[i]] > b[i]) {
            p.push_back(b[i]);

        } else {
            p.push_back(mp[a[i]]);
            mp[a[i]]=b[i];
        }
    }
    sort(p.begin(),p.end());
    long long ans=0;
    REP(i,k-done) {
        ans+=p[i];
    }
    cout<<ans<<endl;
    return 0;
}