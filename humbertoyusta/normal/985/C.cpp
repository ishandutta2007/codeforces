#include<bits/stdc++.h>
#define ull unsigned long long
#define oo int(1e9+7)
using namespace std;

int n,m,k,a[100005],l,pos;
priority_queue<int> q;
long long sol;

int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);

//freopen("a.in","r",stdin);

cin>>n>>k>>l;

for(int i=1; i<=n*k; i++)
    cin>>a[i];

sort(a+1,a+n*k+1);

for(int i=n*k; i>=1; i--){
    if( a[i]<=a[1]+l && (i-1)%k!=0 ){
       q.push(i);
    }
}


for(int i=1; i<=n*k; i+=k){
    if(a[i]>a[1]+l){
       if(q.empty()){ cout<<0<<'\n'; return 0; }
       pos=q.top();
       sol+=a[pos];
       q.pop();
    }
        else sol+=a[i];
}

cout<<sol<<'\n';

return 0;
}