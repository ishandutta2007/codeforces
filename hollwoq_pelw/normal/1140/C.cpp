#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k,s=0,maxi=0;
    cin >> n >> k;
    pair<int,int>p[n];
    priority_queue<int> q;
    for(int i=0;i<n;++i){
        int x,y;
        cin >> x >> y;
        p[i] = {y,x};
    }
    sort(p,p+n);
    for(int i=n-1;i>=0;--i){
        s+=p[i].second;
        q.push(-p[i].second);
        if(q.size()>k){
            s+=q.top();
            q.pop();
        }
        maxi=max(maxi,s*p[i].first);
    }
    return cout << maxi,0;
}