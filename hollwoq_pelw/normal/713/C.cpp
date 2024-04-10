#include <bits/stdc++.h>
using namespace std;int64_t n,a,r=0;priority_queue<int> p;main(){for(cin>>n;n--;)cin>>a,a+=n,p.push(a),p.push(a),r+=p.top()-a,p.pop();cout<<r;}