#include<bits/stdc++.h>
using namespace std;

int n,a[101],sol1,sol2;

int main(){

//freopen("a.in","r",stdin);

ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;

for(int i=1; i<=n/2; i++)
    cin>>a[i];

sort(a+1,a+n/2+1);

int c=1;
for(int i=1; i<=n; i+=2){
    sol1+=(abs(i-a[c++]));
}

int c2=1;
for(int i=2; i<=n; i+=2){
    sol2+=(abs(i-a[c2++]));
}

cout<<min(sol1,sol2)<<'\n';

return 0;
}