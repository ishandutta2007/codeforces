#include<bits/stdc++.h>
#define ull unsigned long long
#define oo int(1e9+7)
using namespace std;

string s;
int c0,c1,n;

int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);

//freopen("a.in","r",stdin);

cin>>n>>s;

if(s=="0"){ cout<<0<<'\n'; return 0; }

for(int i=0; i<n; i++){
    if(s[i]=='0') c0++;
    if(s[i]=='1') c1++;
}

cout<<1;
c1-=2;

while(c0--) cout<<0;


return 0;
}