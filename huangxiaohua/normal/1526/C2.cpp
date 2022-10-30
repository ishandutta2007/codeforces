#include<bits/stdc++.h>
using namespace std;long long p,k,r,t;priority_queue<int> q;main(){cin>>t;while(t--){cin>>k;p+=k;r++;q.push(-k);while(p<0){r--;p+=q.top();q.pop();}}cout<<r;}