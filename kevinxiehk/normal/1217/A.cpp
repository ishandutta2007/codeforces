#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int cc=c;
    if(c%2==1){a++;c--;}
    int more=a-b;
    c/=2;
    if(more>0)more++;
  //  if(more<0)more--;
    c+=more/2;
    if(cc%2==1&&b+cc<a-1)c++;
    cout<<min(cc+1,max(c,0))<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}